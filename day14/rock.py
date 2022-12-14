from cmath import phase, isclose


def as_point(anchor):
    coords = anchor.strip().split(",")
    return int(coords[0]) + int(coords[1])*1j


class Rock:
    def __init__(self, anchors):
        self._anchors = anchors
    @classmethod
    def from_line(cls, line):
        return cls([as_point(anchor) for anchor in line.split("->")])

    @property
    def bound(self):
        return max(anchor.imag for anchor in self._anchors)

    @property
    def x_bounds(self):
        return int(min(anchor.real for anchor in self._anchors)), int(max(anchor.real for anchor in self._anchors))

    def blocks(self, point):
        return any(self._on_line(point, i) for i in range(len(self._anchors) - 1)) or point == self._anchors[0]

    def _on_line(self, point, i):
        diff = point - self._anchors[i]
        line = self._anchors[i+1] - self._anchors[i]
        return abs(diff) <= abs(line) and isclose(phase(diff) - phase(line), 0)