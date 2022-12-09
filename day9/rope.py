class Rope:
    def __init__(self, knots):
        self._knots = [0]*knots
        self._path = set()

    @property
    def _tail(self):
        return self._knots[-1]

    def apply(self, instruction):
        step_vector = instruction.step_vector()
        for _ in range(instruction.size):
            self._make_step(step_vector)
            self._path.add(self._tail)

    def path_length(self):
        return len(self._path)

    def _make_step(self, step_vector):
        self._knots[0] += step_vector
        for knot in range(len(self._knots)-1):
            self._make_step_knot(knot)

    def _make_step_knot(self, knot):
        gap = self._knots[knot] - self._knots[knot+1]
        if not abs(gap) < 2:
            x_distance = abs(gap.real)
            y_distance = abs(gap.imag)
            if x_distance > y_distance:
                step_back = gap.real / x_distance
            elif y_distance > x_distance:
                step_back = gap.imag * 1j / y_distance
            else:
                step_back = gap / x_distance
            self._knots[knot+1] = self._knots[knot] - step_back

