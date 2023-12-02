import uuid

import streamlit as st
from coordination.webapp.widget.drop_down import DropDownOption, DropDown
from coordination.webapp.entity.inference_run import InferenceRun
from coordination.webapp.entity.model_variable import ModelVariableInfo
from coordination.webapp.component.inference_stats_component import InferenceStatsComponent


class InferenceResultsComponent:
    """
    Represents a component that displays inference results for a model variable in an experiment
    from a particular inference run.
    """

    def __init__(self, component_key: str, inference_run: InferenceRun, experiment_id: str,
                 model_variable_info: ModelVariableInfo):
        """
        Creates the component.

        @param component_key: unique identifier for the component in a page.
        @param inference_run: object containing info about an inference run.
        @param experiment_id: experiment id from the inference run.
        @param model_variable_info: object containing info about the model variable.
        """
        self.component_key = component_key
        self.inference_run = inference_run
        self.experiment_id = experiment_id
        self.model_variable_info = model_variable_info

    def create_component(self):
        """
        Displays inference results in different forms depending on the variable selected.
        """
        if not self.experiment_id:
            return

        st.write(f"### {self.experiment_id}")

        idata = self.inference_run.get_inference_data(self.experiment_id)
        if not idata:
            st.write(":red[No inference data found.]")
            return

        inference_stats_component = InferenceStatsComponent(
            component_key=f"{self.component_key}_inference_stats",
            inference_data=idata)
        inference_stats_component.create_component()
