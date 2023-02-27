from __future__ import annotations

from typing import Any, List, Optional, Tuple

import arviz as az
from ast import literal_eval
import numpy as np
import pandas as pd
import pymc as pm
import xarray

from coordination.common.functions import logit
from coordination.model.components.coordination_component import SigmoidGaussianCoordinationComponent, \
    SigmoidGaussianCoordinationComponentSamples
from coordination.model.components.mixture_component import MixtureComponent, MixtureComponentSamples
from coordination.model.components.observation_component import ObservationComponent, ObservationComponentSamples

from coordination.common.functions import sigmoid


class BodySamples:

    def __init__(self, coordination: SigmoidGaussianCoordinationComponentSamples, latent_body: MixtureComponentSamples,
                 obs_body: ObservationComponentSamples):
        self.coordination = coordination
        self.latent_body = latent_body
        self.obs_body = obs_body


class BodySeries:

    def __init__(self, uuid: str, subjects: List[str], num_time_steps_in_coordination_scale: int, obs_body: np.ndarray,
                 body_time_steps_in_coordination_scale: np.ndarray):
        self.uuid = uuid
        self.subjects = subjects
        self.num_time_steps_in_coordination_scale = num_time_steps_in_coordination_scale
        self.obs_body = obs_body
        self.body_time_steps_in_coordination_scale = body_time_steps_in_coordination_scale

    @classmethod
    def from_data_frame(cls, experiment_id: str, evidence_df: pd.DataFrame):
        row_df = evidence_df[evidence_df["experiment_id"] == experiment_id]

        # Add a new axis to represent the single feature dimension
        obs_body = np.array(literal_eval(row_df["body_motion_energy"].values[0]))[:, None, :]

        return cls(
            uuid=row_df["experiment_id"].values[0],
            subjects=literal_eval(row_df["subjects"].values[0]),
            num_time_steps_in_coordination_scale=row_df["num_time_steps_in_coordination_scale"].values[0],
            obs_body=obs_body,
            body_time_steps_in_coordination_scale=np.array(
                literal_eval(row_df["body_motion_energy_time_steps_in_coordination_scale"].values[0])))

    def standardize(self):
        """
        Make sure measurements are between 0 and 1 and per feature. Don't normalize per subject otherwise we lose
        proximity relativity (how close measurements from different subjects are) which is important for the
        coordination model.
        """
        max_value = self.obs_body.max(axis=(0, 2), initial=0)[None, :, None]
        min_value = self.obs_body.min(axis=(0, 2), initial=0)[None, :, None]
        self.obs_body = (self.obs_body - min_value) / (max_value - min_value)

    @property
    def num_time_steps_in_body_scale(self) -> int:
        return self.obs_body.shape[-1]

    @property
    def num_body_features(self) -> int:
        return self.obs_body.shape[-2]

    @property
    def num_subjects(self) -> int:
        return self.obs_body.shape[-3]


class BodyPosteriorSamples:

    def __init__(self, unbounded_coordination: xarray.Dataset, coordination: xarray.Dataset,
                 latent_body: xarray.Dataset):
        self.unbounded_coordination = unbounded_coordination
        self.coordination = coordination
        self.latent_body = latent_body

    @classmethod
    def from_inference_data(cls, idata: Any) -> BodyPosteriorSamples:
        unbounded_coordination = idata.posterior["unbounded_coordination"]
        coordination = sigmoid(unbounded_coordination)
        latent_body = idata.posterior["latent_body"]

        return cls(unbounded_coordination, coordination, latent_body)


class BodyModel:

    def __init__(self, subjects: List[str], self_dependent: bool, sd_mean_uc0: float,
                 sd_sd_uc: float, sd_mean_a0: np.ndarray, sd_sd_aa: np.ndarray, sd_sd_o: np.ndarray,
                 a_mixture_weights: np.ndarray, initial_coordination: Optional[float] = None):
        self.subjects = subjects

        # Single number representing quantity of movement per time step.
        self.num_body_features = 1

        self.coordination_cpn = SigmoidGaussianCoordinationComponent(sd_mean_uc0=sd_mean_uc0,
                                                                     sd_sd_uc=sd_sd_uc)
        if initial_coordination is not  None:
            self.coordination_cpn.parameters.mean_uc0.value = logit(initial_coordination)

        self.latent_body_cpn = MixtureComponent(uuid="latent_body",
                                                num_subjects=len(subjects),
                                                dim_value=self.num_body_features,
                                                self_dependent=self_dependent,
                                                sd_mean_a0=sd_mean_a0,
                                                sd_sd_aa=sd_sd_aa,
                                                a_mixture_weights=a_mixture_weights)
        self.obs_body_cpn = ObservationComponent("obs_body", len(subjects), self.num_body_features, sd_sd_o=sd_sd_o)

    @property
    def parameter_names(self) -> List[str]:
        names = self.coordination_cpn.parameter_names
        names.extend(self.latent_body_cpn.parameter_names)
        names.extend(self.obs_body_cpn.parameter_names)

        return names

    @property
    def obs_body_variable_name(self) -> str:
        return self.obs_body_cpn.uuid

    def draw_samples(self, num_series: int, num_time_steps: int, seed: Optional[int],
                     body_relative_frequency: float) -> BodySamples:
        coordination_samples = self.coordination_cpn.draw_samples(num_series, num_time_steps, seed)
        latent_body_samples = self.latent_body_cpn.draw_samples(num_series,
                                                                relative_frequency=body_relative_frequency,
                                                                coordination=coordination_samples.coordination)
        obs_body_samples = self.obs_body_cpn.draw_samples(latent_component=latent_body_samples.values)

        samples = BodySamples(coordination_samples, latent_body_samples, obs_body_samples)

        return samples

    def fit(self, evidence: BodySeries, burn_in: int, num_samples: int, num_chains: int,
            seed: Optional[int] = None, num_jobs: int = 1) -> Tuple[pm.Model, az.InferenceData]:
        assert evidence.num_subjects == len(self.subjects)
        assert evidence.num_body_features == self.num_body_features

        pymc_model = self._define_pymc_model(evidence)
        with pymc_model:
            idata = pm.sample(num_samples, init="jitter+adapt_diag", tune=burn_in, chains=num_chains, random_seed=seed,
                              cores=num_jobs)

        return pymc_model, idata

    def _define_pymc_model(self, evidence: BodySeries):
        coords = {"subject": self.subjects,
                  "body_feature": ["total_energy"],
                  "coordination_time": np.arange(evidence.num_time_steps_in_coordination_scale),
                  "body_time": np.arange(evidence.num_time_steps_in_body_scale)}

        pymc_model = pm.Model(coords=coords)
        with pymc_model:
            _, coordination, _ = self.coordination_cpn.update_pymc_model(time_dimension="coordination_time")
            latent_body, _, _, _ = self.latent_body_cpn.update_pymc_model(
                coordination=coordination[evidence.body_time_steps_in_coordination_scale],
                subject_dimension="subject",
                time_dimension="body_time",
                feature_dimension="body_feature")
            self.obs_body_cpn.update_pymc_model(latent_component=latent_body,
                                                subject_dimension="subject",
                                                feature_dimension="body_feature",
                                                time_dimension="body_time",
                                                observed_values=evidence.obs_body)

        return pymc_model

    def prior_predictive(self, evidence: BodySeries, num_samples: int, seed: Optional[int] = None):
        pymc_model = self._define_pymc_model(evidence)
        with pymc_model:
            idata = pm.sample_prior_predictive(samples=num_samples, random_seed=seed)

        return pymc_model, idata

    def clear_parameter_values(self):
        self.coordination_cpn.parameters.clear_values()
        self.latent_body_cpn.parameters.clear_values()
        self.obs_body_cpn.parameters.clear_values()

    @staticmethod
    def inference_data_to_posterior_samples(idata: az.InferenceData) -> BodyPosteriorSamples:
        return BodyPosteriorSamples.from_inference_data(idata)
