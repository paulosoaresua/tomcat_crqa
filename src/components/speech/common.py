from datetime import datetime
from typing import Dict, List


class SegmentedUtterance:
    def __init__(self, start: datetime, end: datetime):
        self.start = start
        self.end = end
        # A value per feature
        self.average_vocalics: Dict[str, float] = {}


class VocalicsComponent:
    def __init__(self, series_a: List[SegmentedUtterance], series_b: List[SegmentedUtterance]):
        self.series_a = series_a
        self.series_b = series_b

        # assuming that series a and series b have the same vocalics types
        if len(self.series_a) > 0:
            self.feature_names = list(self.series_a[0].average_vocalics.keys())
        elif len(self.series_b) > 0:
            self.feature_names = list(self.series_b[0].average_vocalics.keys())
        else:
            self.feature_names = []
