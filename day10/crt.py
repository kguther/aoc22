class CRT:
    def __init__(self):
        self._screen = [["."]*40, ["."]*40, ["."]*40, ["."]*40, ["."]*40, ["."]*40]
        self._x = 0
        self._y = 0

    def mark(self, register):
        if abs(register-self._x) < 2:
            self._screen[self._y][self._x] = "#"
        self._y += (self._x+1) // 40
        self._x = (self._x + 1) % 40

    def draw(self):
        for line in self._screen:
            print("".join(line))

