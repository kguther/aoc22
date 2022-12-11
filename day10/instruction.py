ADD_CMD = "addx"

class Instruction:
    def __init__(self, cmd):
        parts = cmd.split(" ")
        self._cmd = parts[0]
        self._args = parts[1:]

    @property
    def cycles(self):
        if self._cmd == ADD_CMD:
            return 2
        return 1

    def apply(self, register):
        if self._cmd == ADD_CMD:
            return register + int(self._args[0])
        return register


def read_instructions(filename):
    with open(filename) as ifile:
        return [Instruction(line.strip()) for line in ifile]