class CPU:
    def __init__(self, crt):
        self._register = 1
        self._cycle = 0
        self.signal = 0
        self._measured_cycle = 20
        self._crt = crt

    def _step_cycle(self, n):
        for _ in range(n):
            self._cycle += 1
            self._crt.mark(self._register)

    def apply_instruction(self, instruction):
        self._step_cycle(instruction.cycles)
        if self._cycle >= self._measured_cycle:
            self.signal += self._register * self._measured_cycle
            self._measured_cycle += 40
        self._register = instruction.apply(self._register)
