import numpy as np

DEFAULT_UNB_COORDINATION_MEAN_PARAM = 0
DEFAULT_UNB_COORDINATION_SD_PARAM = 1
DEFAULT_TIME_SCALE_DENSITY = 1.0
DEFAULT_SUBJECT_REPETITION_FLAG = True
DEFAULT_FIXED_SUBJECT_SEQUENCE_FLAG = False
DEFAULT_NUM_SUBJECTS = 3
DEFAULT_LATENT_DIMENSION_SIZE = 2
DEFAULT_OBSERVATION_DIMENSION_SIZE = 4
DEFAULT_SELF_DEPENDENCY = True
DEFAULT_LATENT_MEAN_PARAM = np.zeros(DEFAULT_LATENT_DIMENSION_SIZE)
DEFAULT_LATENT_SD_PARAM = np.ones(DEFAULT_LATENT_DIMENSION_SIZE)
DEFAULT_OBSERVATION_SD_PARAM = np.ones(DEFAULT_OBSERVATION_DIMENSION_SIZE)
DEFAULT_SHARING_ACROSS_SUBJECTS = True
DEFAULT_SHARING_ACROSS_DIMENSIONS = False
DEFAULT_NUM_TIME_STEPS = 100
DEFAULT_MLP_MEAN_WEIGHTS = 0
DEFAULT_MLP_SD_WEIGHTS = 1
DEFAULT_MLP_ACTIVATION = "linear"
DEFAULT_MLP_NUM_HIDDEN_LAYERS = 0
DEFAULT_MLP_HIDDEN_DIMENSION_SIZE = 4

DEFAULT_SEED = 0
DEFAULT_NUM_SAMPLED_SERIES = 1
DEFAULT_BURN_IN = 1000
DEFAULT_NUM_SAMPLES = 1000
DEFAULT_NUM_CHAINS = 2
DEFAULT_NUM_JOBS = DEFAULT_NUM_CHAINS
DEFAULT_INIT_METHOD = "jitter+adapt_diag"
DEFAULT_TARGET_ACCEPT = 0.8
