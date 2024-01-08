from dataclasses import dataclass

import numpy as np

from coordination.model.config_bundle.bundle import ModelConfigBundle
from coordination.common.normalization import (NORMALIZATION_PER_FEATURE,
                                               NORMALIZATION_PER_SUBJECT_AND_FEATURE)


@dataclass
class VocalicConfigBundle(ModelConfigBundle):
    """
    Container for the different parameters of the vocalic model.
    """

    num_subjects = 3
    num_time_steps_in_coordination_scale = 100
    observation_normalization = NORMALIZATION_PER_SUBJECT_AND_FEATURE
    state_space_dimension_size = 4
    state_space_dimension_names = ["pitch", "intensity", "jitter", "shimmer"]
    self_dependent = True
    num_vocalic_features = 4
    vocalic_feature_names = ["pitch", "intensity", "jitter", "shimmer"]

    # Hyper priors
    mean_mean_uc0 = 0.0
    sd_mean_uc0 = 5.0
    sd_sd_uc = 1.0
    mean_mean_a0 = 0.0
    sd_mean_a0 = 1.0
    sd_sd_a = 1.0
    sd_sd_o = 1.0

    share_mean_a0_across_subjects = False
    share_mean_a0_across_dimensions = False
    share_sd_a_across_subjects = True
    share_sd_a_across_dimensions = False
    share_sd_o_across_subjects = True
    share_sd_o_across_dimensions = True

    sampling_time_scale_density = 1.0
    allow_sampled_subject_repetition = False
    fix_sampled_subject_sequence = True

    # Some parameters are given and others fixed.
    mean_uc0 = None
    sd_uc = 0.5
    mean_a0 = None
    sd_a = None
    sd_o = 0.1
    # Fixed coordination series for sampling.
    coordination_samples: np.ndarray = None

    # Evidence and metadata filled before inference.
    time_steps_in_coordination_scale: np.ndarray = None
    subject_indices: np.ndarray = None
    prev_time_same_subject: np.ndarray = None
    prev_time_diff_subject: np.ndarray = None
    observed_values: np.ndarray = None

    # To transform a high-dimension state space to a lower dimension observation in case we
    # want to observe position only.
    num_hidden_layers = 0
    hidden_dimension_size = 0
    activation = "linear"
    weights = [np.eye(4, 4)]
    mean_w0 = 0.0
    sd_w0 = 1.0


class Vocalic2DConfigBundle(ModelConfigBundle):
    """
    Container for the different parameters of the vocalic 2D model.
    """

    num_subjects = 3
    num_time_steps_in_coordination_scale = 100
    observation_normalization = NORMALIZATION_PER_FEATURE
    num_vocalic_features = 4
    vocalic_feature_names = ["pitch", "intensity", "jitter", "shimmer"]

    # Hyper priors
    mean_mean_uc0 = 0.0
    sd_mean_uc0 = 1.0
    sd_sd_uc = 1.0
    mean_mean_a0 = 0.0
    sd_mean_a0 = 1.0
    sd_sd_a = 1.0
    sd_sd_o = 1.0

    share_mean_a0_across_subjects = False
    share_mean_a0_across_dimensions = False
    share_sd_a_across_subjects = True
    share_sd_a_across_dimensions = True
    share_sd_o_across_subjects = True
    share_sd_o_across_dimensions = True

    sampling_time_scale_density = 1.0
    allow_sampled_subject_repetition = False
    fix_sampled_subject_sequence = True

    # For sampling. Defaults to None for inference.
    mean_uc0 = None
    sd_uc = None
    mean_a0 = None
    sd_a = None
    sd_o = None
    # Fixed coordination series for sampling.
    coordination_samples: np.ndarray = None

    # Evidence and metadata filled before inference.
    time_steps_in_coordination_scale: np.ndarray = None
    subject_indices: np.ndarray = None
    prev_time_same_subject: np.ndarray = None
    prev_time_diff_subject: np.ndarray = None
    observed_values: np.ndarray = None

    # To transform a high-dimension state space to a lower dimension observation in case we
    # want to observe position only.
    num_hidden_layers = 0
    hidden_dimension_size = 0
    activation = "linear"
    # Only position is used
    weights = [np.ones((1, 4))]  # From position to 4 vocalic features
    mean_w0 = 0.0
    sd_w0 = 1.0
