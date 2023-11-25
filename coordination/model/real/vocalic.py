from typing import Optional

import numpy as np
import pymc as pm

from coordination.model.config.vocalic import VocalicConfigBundle
from coordination.model.model import Model
from coordination.module.component_group import ComponentGroup
from coordination.module.coordination.sigmoid_gaussian_coordination import \
    SigmoidGaussianCoordination
from coordination.module.latent_component.serial_gaussian_latent_component import \
    SerialGaussianLatentComponent
from coordination.module.observation.serial_gaussian_observation import \
    SerialGaussianObservation


class VocalicModel(Model):
    """
    This class represents a vocalic model where subjects are talking to each other and their
    speech vocalics are observed as they finish talking.
    """

    def __init__(
        self, config_bundle: VocalicConfigBundle, pymc_model: Optional[pm.Model] = None
    ):
        """
        Creates a vocalic model.

        @param config_bundle: container for the different parameters of the vocalic model.
        @param pymc_model: a PyMC model instance where modules are to be created at. If not
            provided, it will be created along with this model instance.
        """

        self.config_bundle = config_bundle
        if not pymc_model:
            pymc_model = pm.Model()

        coordination = SigmoidGaussianCoordination(
            pymc_model=pymc_model,
            sd_mean_uc0=config_bundle.sd_mean_uc0,
            sd_sd_uc=config_bundle.sd_sd_uc,
            num_time_steps=config_bundle.num_time_steps_in_coordination_scale,
        )

        # Save a direct reference to state_space and observation for easy access in the parameter
        # setting functions in this class.
        self.state_space = SerialGaussianLatentComponent(
            uuid="state_space",
            pymc_model=pymc_model,
            num_subjects=config_bundle.num_subjects,
            dimension_size=config_bundle.state_space_dimension_size,
            self_dependent=config_bundle.self_dependent,
            mean_mean_a0=config_bundle.mean_mean_a0,
            sd_mean_a0=config_bundle.sd_mean_a0,
            sd_sd_a=config_bundle.sd_sd_a,
            share_mean_a0_across_subjects=config_bundle.share_mean_a0_across_subjects,
            share_sd_a_across_subjects=config_bundle.share_sd_a_across_subjects,
            share_mean_a0_across_dimensions=config_bundle.share_mean_a0_across_dimensions,
            share_sd_a_across_dimensions=config_bundle.share_sd_a_across_dimensions,
            dimension_names=config_bundle.state_space_dimension_names,
            sampling_time_scale_density=config_bundle.sampling_time_scale_density,
            allow_sampled_subject_repetition=config_bundle.allow_sampled_subject_repetition,
            fix_sampled_subject_sequence=config_bundle.fix_sampled_subject_sequence,
        )

        self.observation = SerialGaussianObservation(
            uuid="speech_vocalics",
            pymc_model=pymc_model,
            num_subjects=config_bundle.num_subjects,
            dimension_size=config_bundle.num_vocalic_features,
            dimension_names=config_bundle.vocalic_feature_names,
            sd_sd_o=config_bundle.sd_sd_o,
            share_sd_o_across_subjects=config_bundle.share_sd_o_across_subjects,
            share_sd_o_across_dimensions=config_bundle.share_sd_o_across_dimensions,
        )

        group = ComponentGroup(
            uuid="group",
            pymc_model=pymc_model,
            latent_component=self.state_space,
            observations=[self.observation],
        )

        super().__init__(
            name="vocalic_model",
            pymc_model=pymc_model,
            coordination=coordination,
            component_groups=[group],
            coordination_samples=config_bundle.coordination_samples,
        )

        self.coordination.parameters.mean_uc0.value = (
            np.ones(1) * config_bundle.mean_uc0
        )
        self.coordination.parameters.sd_uc.value = np.ones(1) * config_bundle.sd_uc
        self.state_space.parameters.mean_a0.value = config_bundle.mean_a0
        self.state_space.parameters.sd_a.value = config_bundle.sd_a
        self.observation.parameters.sd_o.value = config_bundle.sd_o
        self.coordination.num_time_steps = (
            config_bundle.num_time_steps_in_coordination_scale
        )
        self.state_space.time_steps_in_coordination_scale = (
            config_bundle.time_steps_in_coordination_scale
        )
        self.state_space.subject_indices = config_bundle.subject_indices
        self.state_space.prev_time_same_subject = config_bundle.prev_time_same_subject
        self.state_space.prev_time_diff_subject = config_bundle.prev_time_diff_subject
        self.observation.observed_values = config_bundle.observed_values
        self.observation.time_steps_in_coordination_scale = (
            config_bundle.time_steps_in_coordination_scale
        )
        self.observation.subject_indices = config_bundle.subject_indices
