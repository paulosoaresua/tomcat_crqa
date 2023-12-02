import streamlit as st

from coordination.webapp.component.inference_run_selection_component import \
    InferenceRunSelectionComponent
from coordination.webapp.component.experiment_id_multi_selection_component import \
    ExperimentIDMultiSelectionComponent
from coordination.webapp.component.model_variable_selection_component import \
    ModelVariableSelectionComponent
from coordination.webapp.component.inference_results_component import InferenceResultsComponent


class RunVsRunPage:
    """
    This class represents a page to compare two inference runs side by side.
    """

    def __init__(self, page_key: str):
        """
        Creates the page object.

        @param page_key: unique identifier for the page. Components of the page will append to
            this key to form their keys.
        """
        self.page_key = page_key

    def create_page(self):
        """
        Creates the page by adding different components to the screen.
        """
        col_left, col_right = st.columns(2)
        with col_left:
            RunVsRunPage._populate_column(column_key=f"{self.page_key}_left_col")

        with col_right:
            RunVsRunPage._populate_column(column_key=f"{self.page_key}_right_col")

    @staticmethod
    def _populate_column(column_key: str):
        """
        Populates a column where one can choose an inference run, experiment ids and
            associated variables to see inference results for them.

        @param column_key: unique identifier for the column. Components of the column will append
            to this key to form their keys.
        """
        inference_run_component = InferenceRunSelectionComponent(
            component_key=f"{column_key}_inference_run_selector",
            inference_dir=st.session_state["inference_results_dir"])
        inference_run_component.create_component()

        experiment_ids_component = ExperimentIDMultiSelectionComponent(
            component_key=f"{column_key}_experiments_selector",
            all_experiment_ids=inference_run_component.selected_inference_run_.experiment_ids)
        experiment_ids_component.create_component()

        if not inference_run_component.selected_inference_run_.run_id:
            # Do not render anything below this until an inference run is selected.
            return

        model_variable_component = ModelVariableSelectionComponent(
            component_key=f"{column_key}_model_variable_selector",
            inference_run=inference_run_component.selected_inference_run_
        )
        model_variable_component.create_component()

        for experiment_id in experiment_ids_component.selected_experiment_ids_:
            inference_results_component = InferenceResultsComponent(
                component_key=f"{column_key}_{experiment_id}_inference_results",
                inference_run=inference_run_component.selected_inference_run_,
                experiment_id=experiment_id,
                model_variable_info=model_variable_component.selected_model_variable_,
                model_variable_dimension=model_variable_component.selected_dimension_name_)
            inference_results_component.create_component()
