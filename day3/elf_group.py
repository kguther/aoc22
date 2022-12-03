from priorities import priority


class ElfGroup:
    def __init__(self, items):
        self._items = [set(item.strip()) for item in items]

    def badge(self):
        return self._items[0].intersection(*self._items[1:])

    def badge_priority(self):
        return priority(next(iter(self.badge())))


def read_groups(filename):
    with open(filename) as lists:
        items = [line for line in lists]
    return [ElfGroup(items[i:i+3]) for i in range(0,len(items),3)]
