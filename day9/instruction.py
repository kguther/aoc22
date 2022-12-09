class Instruction:
    def __init__(self, descriptor):
        parts = descriptor.split(" ")
        self._direction = parts[0]
        self.size = int(parts[1])

    def step_vector(self):
        if self._direction == "R":
            return 1
        elif self._direction == "L":
            return -1
        elif self._direction == "U":
            return 1j
        else:
            return -1j

def read_instructions(filename):
    with open(filename) as ifile:
        return [Instruction(line.strip()) for line in ifile]
