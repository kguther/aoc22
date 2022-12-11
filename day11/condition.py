class Condition:
    def __init__(self, divisor, target_true, target_false):
        self._divisor = int(divisor)
        self._target_true = int(target_true)
        self._target_false = int(target_false)

    def __call__(self, new):
        if new % self._divisor == 0:
            return self._target_true
        return self._target_false