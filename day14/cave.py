from rock import Rock

DIRECTION = [1j, -1 + 1j, 1 + 1j]
class Cave:
    def __init__(self, rock_formation):
        self._rock_formation = rock_formation
        self._sand = set()
        self._bound = max(rock.bound for rock in self._rock_formation)
        floor = (self._bound + 2) * 1j
        self._rock_formation.append(Rock([-10000 + floor, 10000 + floor]))

    @property
    def sand_amount(self):
        return len(self._sand)

    def print(self):
        min_x = min(rock.x_bounds[0] for rock in self._rock_formation)
        max_x = max(rock.x_bounds[1] for rock in self._rock_formation)
        for i in range(int(self._bound)+1):
            line = []
            for j in range(min_x, max_x):
                point = j + i * 1j
                if point in self._sand:
                    line.append("o")
                elif self._blocked(point):
                    line.append("#")
                else:
                    line.append(".")
            print("".join(line))

    def fill(self):
        filling = True
        i = 0
        while(filling):
            filling = self._trace_sand_particle()
            i += 1
            if i % 100 == 0:
                print(self.sand_amount)

    def _blocked(self, point):
        return point in self._sand or any(rock.blocks(point) for rock in self._rock_formation)

    def _trace_sand_particle(self):
        sand_spawn = 500
        position = sand_spawn
        while(sand_spawn not in self._sand):
            old_position = position
            position = self._iterate(position)
            if old_position == position:
                self._sand.add(position)
                return True
        return False

    def _iterate(self, point):
        for step in DIRECTION:
            new_point = point + step
            if not self._blocked(new_point):
                return new_point
        return point


def read_cave(filename):
    with open(filename) as ifile:
        rock_formation = [Rock.from_line(line) for line in ifile]
    return Cave(rock_formation)
