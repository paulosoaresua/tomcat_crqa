from __future__ import annotations

from typing import Optional

import numpy as np
import pymc as pm
from scipy.stats import beta

from coordination.common.functions import sigmoid
from coordination.common.types import TensorTypes
from coordination.common.utils import adjust_dimensions
from coordination.module.constants import (DEFAULT_NUM_TIME_STEPS,
                                           DEFAULT_UNB_COORDINATION_MEAN_PARAM,
                                           DEFAULT_UNB_COORDINATION_SD_PARAM)
from coordination.module.coordination.coordination import Coordination
from coordination.module.module import ModuleParameters, ModuleSamples
from coordination.module.parametrization2 import (HalfNormalParameterPrior,
                                                  NormalParameterPrior,
                                                  Parameter)


class ConstantCoordination(Coordination):
    """
    This class models coordination as a constant variable that does not change over time:
    C ~ Beta(a, b).
    """

    def __init__(
            self,
            pymc_model: pm.Model,
            num_time_steps: int = DEFAULT_NUM_TIME_STEPS,
            alpha: float = 1,
            beta: float = 1,
            coordination_random_variable: Optional[pm.Distribution] = None,
            observed_value: Optional[float] = None,
    ):
        """
        Creates a coordination module with an unbounded auxiliary variable.

        @param pymc_model: a PyMC model instance where modules are to be created at.
        @param num_time_steps: number of time steps in the coordination scale.
        @param mean_mean_uc0: mean of the hyper-prior of mu_uc0 (mean of the initial value of the
            unbounded coordination).
        @param alpha: parameter alpha of the Beta distribution.
        @param beta: parameter beta of the beta distribution.
        @param coordination_random_variable: random variable to be used in a call to
            create_random_variables. If not set, it will be created in such a call.
        @param observed_value: observed value of coordination. If a value is set, the variable is
        not latent anymore.
        """
        super().__init__(
            pymc_model=pymc_model,
            # We don'' infer the parameters of the Beta distribution. They must be given.
            parameters=None,
            num_time_steps=num_time_steps,
            coordination_random_variable=coordination_random_variable,
            observed_values=observed_value,
        )
        self.alpha = alpha
        self.beta = beta

    def draw_samples(
            self, seed: Optional[int], num_series: int
    ) -> SigmoidGaussianCoordinationSamples:
        """
        Draw coordination samples. A sample is a time series of coordination.

        @param seed: random seed for reproducibility.
        @param num_series: how many series of samples to generate.
        @raise ValueError: if either mean_uc0 or sd_uc is None.
        @return: coordination samples. One coordination series per row.
        """
        super().draw_samples(seed, num_series)

        if self.alpha is None:
            raise ValueError(f"Value of the parameter alpha is undefined.")

        if self.beta is None:
            raise ValueError(f"Value of the parameter beta is undefined.")

        coordination = beta(self.alpha, self.beta).rvs(num_series)
        values = np.ones_like((num_series, self.num_time_steps)) * coordination[:, None]

        return ModuleSamples(values=values)

    def create_random_variables(self):
        """
        Creates parameters and coordination variables in a PyMC model.
        """

        with self.pymc_model:
            if self.coordination_random_variable is None:
                # Add coordinates to the model
                if self.time_axis_name not in self.pymc_model.coords:
                    self.pymc_model.add_coord(
                        name=self.time_axis_name, values=np.arange(self.num_time_steps)
                    )

                single_coordination = pm.Beta(
                    name="single_coordination",
                    alpha=self.alpha,
                    beta=self.beta,
                    size=1
                )

                self.coordination_random_variable = pm.Deterministic(
                    name=self.uuid,
                    var=single_coordination.repeat(self.num_time_steps),
                    dims=[self.time_axis_name]
                )
