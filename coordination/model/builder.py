from coordination.model.config_bundle.bundle import ModelConfigBundle
from coordination.model.config_bundle.vocalic import VocalicConfigBundle
from coordination.model.real.vocalic import VocalicModel
from coordination.model.template import ModelTemplate


class ModelBuilder:
    """
    This class is responsible from instantiating a concrete model object from its name.
    """

    MODELS = {"conversation", "spring", "vocalic", "vocalic_semantic"}

    @staticmethod
    def build_bundle(model_name: str) -> ModelConfigBundle:
        """
        Gets an instance of a model config bundle.

        @param model_name: name of the model.
        @raise ValueError: if the model name is not in the list of valid models.
        @return: an instance of the model config bundle.
        """
        if model_name not in ModelBuilder.MODELS:
            raise ValueError(f"Invalid model ({model_name}).")

        if model_name == "conversation":
            return None

        if model_name == "spring":
            return None

        if model_name == "vocalic":
            return VocalicConfigBundle()

        if model_name == "vocalic_semantic":
            return None

    @staticmethod
    def build_model(model_name: str, config_bundle: ModelConfigBundle) -> ModelTemplate:
        """
        Gets an instance of the model.

        @param model_name: name of the model.
        @param config_bundle: a config bundle containing model's parameter values.
        @raise ValueError: if the model name is not in the list of valid models.
        @return: an instance of the model.
        """
        if model_name not in ModelBuilder.MODELS:
            raise ValueError(f"Invalid model ({model_name}).")

        if model_name == "conversation":
            return None

        if model_name == "spring":
            return None

        if model_name == "vocalic":
            return VocalicModel(config_bundle=config_bundle)

        if model_name == "vocalic_semantic":
            return None
