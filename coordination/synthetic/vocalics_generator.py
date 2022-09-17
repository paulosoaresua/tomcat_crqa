from typing import List, Optional

from datetime import datetime

import numpy as np
import random

from scipy.stats import norm

from coordination.component.speech.common import SegmentedUtterance, VocalicsSparseSeries


class VocalicsGenerator:
    """
    This class generates synthetic evidence for the vocalics component of a coordination model.
    """

    def __init__(self, coordination_series: np.ndarray, num_vocalic_features: int, time_scale_density: float):
        self._coordination_series = coordination_series
        self._num_vocalic_features = num_vocalic_features
        self._time_scale_density = time_scale_density

    def generate(self, seed: Optional[int] = None) -> VocalicsSparseSeries:
        if seed is not None:
            random.seed(seed)
            np.random.seed(seed)

        mask_a, mask_b = self._generate_random_masks()

        num_time_steps = len(self._coordination_series)
        values = np.zeros((self._num_vocalic_features, num_time_steps))

        # Subjects A and B
        previous_time_a = None
        previous_time_b = None
        previous_self = [None] * num_time_steps
        previous_other = [None] * num_time_steps
        for t in range(num_time_steps):
            current_coordination = self._coordination_series[t]
            current_a = None
            current_b = None

            previous_a = None if previous_time_a is None else values[:, previous_time_a]
            previous_b = None if previous_time_b is None else values[:, previous_time_b]

            if mask_a[t] == 1:
                current_a = self._sample(previous_a, previous_b, current_coordination)
                values[:, t] = current_a
                previous_self[t] = previous_time_a
                previous_other[t] = previous_time_b
            elif mask_b[t] == 1:
                current_b = self._sample(previous_b, previous_a, current_coordination)
                values[:, t] = current_b
                previous_self[t] = previous_time_b
                previous_other[t] = previous_time_a

            previous_time_a = t if current_a is not None else previous_time_a
            previous_time_b = t if current_b is not None else previous_time_b

        utterance_a = SegmentedUtterance("A", datetime.now(), datetime.now(), "")
        utterance_b = SegmentedUtterance("B", datetime.now(), datetime.now(), "")
        utterances: List[Optional[SegmentedUtterance]] = [None] * num_time_steps
        for t in range(num_time_steps):
            if mask_a[t] == 1:
                utterances[t] = utterance_a
            elif mask_b[t] == 1:
                utterances[t] = utterance_b

        mask = np.bitwise_or(mask_a, mask_b)
        return VocalicsSparseSeries(utterances=utterances, previous_from_self=previous_self,
                                    previous_from_other=previous_other, values=values, mask=mask)

    def _generate_random_masks(self) -> np.ndarray:
        """
        Generates random time steps in which series A and B have data available
        """

        num_time_steps = len(self._coordination_series)
        num_selected_time_steps = int(num_time_steps * self._time_scale_density)
        selected_time_steps = sorted(random.sample(range(num_time_steps), num_selected_time_steps))

        # The selected time steps are split between series A and B
        mask_a = np.zeros(num_time_steps).astype(np.int)
        mask_b = np.zeros(num_time_steps).astype(np.int)

        for i, t in enumerate(selected_time_steps):
            if i % 2 == 0:
                mask_a[t] = 1
            else:
                mask_b[t] = 1

        return mask_a, mask_b

    def _sample(self, previous_self: Optional[float], previous_other: Optional[float], coordination: float):
        raise Exception("Not implemented in this class.")


class VocalicsGeneratorForDiscreteCoordination(VocalicsGenerator):

    def __init__(self, mean_prior_vocalics: np.array, std_prior_vocalics: np.array,
                 std_uncoordinated_vocalics: np.array, std_coordinated_vocalics: np.array, *args, **kwargs):
        super().__init__(*args, **kwargs)

        assert len(mean_prior_vocalics) == self._num_vocalic_features
        assert len(std_prior_vocalics) == self._num_vocalic_features
        assert len(std_uncoordinated_vocalics) == self._num_vocalic_features
        assert len(std_coordinated_vocalics) == self._num_vocalic_features

        self._prior_vocalics = norm(loc=mean_prior_vocalics, scale=std_prior_vocalics)

        self._std_uncoordinated_vocalics = std_uncoordinated_vocalics
        self._std_coordinated_vocalics = std_coordinated_vocalics

    def _sample(self, previous_self: Optional[float], previous_other: Optional[float], coordination: float):
        if previous_other is None:
            distribution = self._prior_vocalics
        else:
            if coordination == 0:
                # The current value depends on the previous value of the same series when there's no coordination
                if previous_self is None:
                    distribution = self._prior_vocalics
                else:
                    distribution = norm(loc=previous_self, scale=self._std_uncoordinated_vocalics)
            else:
                # The current value depends on the previous value of the other series when there's coordination
                if previous_other is None:
                    distribution = self._prior_vocalics
                else:
                    distribution = norm(loc=previous_other, scale=self._std_coordinated_vocalics)

        return distribution.rvs()


class VocalicsGeneratorForContinuousCoordination(VocalicsGenerator):

    def __init__(self, mean_prior_vocalics: np.array, std_prior_vocalics: np.array, std_coordinated_vocalics: np.array,
                 *args, **kwargs):
        super().__init__(*args, **kwargs)

        assert len(mean_prior_vocalics) == self._num_vocalic_features
        assert len(std_prior_vocalics) == self._num_vocalic_features
        assert len(std_coordinated_vocalics) == self._num_vocalic_features

        self._prior_vocalics = norm(loc=mean_prior_vocalics, scale=std_prior_vocalics)

        self._mean_prior_vocalics = mean_prior_vocalics
        self._std_coordinated_vocalics = std_coordinated_vocalics

    def _sample(self, previous_self: Optional[float], previous_other: Optional[float], coordination: float):
        if previous_other is None:
            distribution = self._prior_vocalics
        else:
            if previous_self is None:
                D = previous_other - self._mean_prior_vocalics
                distribution = norm(loc=D * coordination + self._mean_prior_vocalics,
                                    scale=self._std_coordinated_vocalics)
            else:
                D = previous_other - previous_self
                distribution = norm(loc=D * coordination + previous_self,
                                    scale=self._std_coordinated_vocalics)

        return distribution.rvs()
