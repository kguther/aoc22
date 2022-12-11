class Operation:
    def __init__(self, operation_string):
        self._def = operation_string

    def __call__(self, old):
        new = eval(self._def)
        return new