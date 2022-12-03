from priorities import priority


class Rucksack:
    def __init__(self, items):
        compartment_size = len(items) // 2
        self._compartment_1 = items[:compartment_size]
        self._compartment_2 = items[compartment_size:len(items)]

    def duplicate_items(self):
        return {item for item in self._compartment_2 if item in self._compartment_1}

    def duplicate_priorities(self):
        duplicates = self.duplicate_items()
        return sum(priority(item) for item in duplicates)

    def __repr__(self):
        return f"{self._compartment_1} | {self._compartment_2}"


def read_items(filename):
    with open(filename) as lists:
        rucksacks = [Rucksack(item) for item in lists]
    return rucksacks
