class Monkey:
    def __init__(self, items, operation, condition):
        self._items = items
        self._operation = operation
        self._condition = condition
        self.inspected_items = 0
        self._global_modulus = 0

    def set_global_modulus(self, global_modulus):
        self._global_modulus = global_modulus

    def add_item(self, item):
        self._items.append(item)

    def _inspect_item(self, index):
        self._items[index] = self._operation(self._items[index]) % self._global_modulus

    def _throw_item(self, index, monkey_group, target):
        monkey_group[target].add_item(self._items[index])

    def check_items(self, monkey_group):
        for index in range(len(self._items)):
            self.inspected_items += 1
            self._inspect_item(index)
            target_monkey = self._condition(self._items[index])
            self._throw_item(index, monkey_group, target_monkey)
        self._items = []
