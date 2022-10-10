from typing import Any, Dict, List, Optional, Tuple

from datetime import datetime, timedelta
import logging

import psycopg2
from tqdm import tqdm
import numpy as np

from coordination.config.database_config import DatabaseConfig
from coordination.entity.trial_metadata import TrialMetadata
from coordination.entity.vocalics_series import VocalicsSeries

logger = logging.getLogger()


class VocalicFeature:
    """
    List of available vocalic features
    """
    PITCH = "pitch"
    INTENSITY = "intensity"


class VocalicsReader:
    """
    This class reads vocalic features from a database
    """

    __FEATURE_MAP = {
        "pitch": "f0final_sma",
        "intensity": "wave_rmsenergy_sma"
    }

    def __init__(self, database_config: DatabaseConfig, features: List[str]):
        self._database_config = database_config
        self._features = features

    def read(self,
             trial_metadata: TrialMetadata,
             baseline_time: datetime,
             time_range: Optional[Tuple[datetime, datetime]] = None) -> Dict[str, VocalicsSeries]:
        """
        Reads vocalic features series from a specific trial.
        """

        vocalics_series_per_subject: Dict[str, VocalicsSeries] = {}

        with self._connect() as connection:
            records = VocalicsReader._read_records(connection, trial_metadata.id, self._features, time_range)

            if len(records) > 0:
                # Records are already sorted by timestamp
                vocalics_per_subject: Dict[str, Tuple[List[float], List[datetime]]] = {}
                pbar = tqdm(total=len(records), desc="Parsing vocalics")
                for subject_id, seconds_offset, *feature_values in records:
                    subject_id = trial_metadata.subject_id_map[subject_id]

                    timestamp = baseline_time + timedelta(seconds=seconds_offset)

                    values = []  # List with one value per feature
                    for feature_value in feature_values:
                        values.append(feature_value)

                    if subject_id not in vocalics_per_subject:
                        vocalics_per_subject[subject_id] = ([], [])

                    vocalics_per_subject[subject_id][0].append(np.array(values).reshape(-1, 1))
                    vocalics_per_subject[subject_id][1].append(timestamp)

                    pbar.update()

                # From list to numpy
                for subject_id in vocalics_per_subject.keys():
                    vocalics_series_per_subject[subject_id] = VocalicsSeries(
                        np.concatenate(vocalics_per_subject[subject_id][0], axis=1),
                        vocalics_per_subject[subject_id][1])
            else:
                logger.error(f"No vocalic features were found for trial {trial_metadata.number}.")

        return vocalics_series_per_subject

    def _connect(self) -> Any:
        try:
            connection = psycopg2.connect(host=self._database_config.address,
                                          port=self._database_config.port,
                                          database=self._database_config.database)
        except (Exception, psycopg2.Error) as error:
            raise RuntimeError(
                "Error while connecting to the database: " + str(error))

        return connection

    @staticmethod
    def _read_records(connection: Any, trial_id: str, features: List[str],
                      time_range: Optional[Tuple[float, float]]) -> List[Tuple[Any]]:

        db_feature_names = [VocalicsReader.__FEATURE_MAP[feature] for feature in features]
        db_feature_list = ",".join(db_feature_names)

        if time_range is None:
            query = f"SELECT participant, seconds_offset, {db_feature_list} FROM features WHERE " + \
                    "trial_id = %s ORDER BY participant, seconds_offset"
            cursor = connection.cursor()
            cursor.execute(query, (trial_id,))
        else:
            query = f"SELECT participant, seconds_offset, {db_feature_list} FROM features WHERE " + \
                    "trial_id = %s AND seconds_offset BETWEEN %f AND %f ORDER BY participant, seconds_offset"
            cursor = connection.cursor()
            cursor.execute(query, (trial_id, time_range[0], time_range[1],))

        return cursor.fetchall()
