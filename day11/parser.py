from condition import Condition
from monkey import Monkey
from operation import Operation


def read_monkeys(filename):
    monkeys = []
    items = []
    operation = Operation("")
    target_true = 0
    test_divisor = 1
    global_modulus = 1
    with open(filename) as ifile:
        for line in ifile:
            content = line.strip()
            if content.startswith("Starting items"):
                items = [int(item) for item in content.split(":")[1].split(",")]
            elif content.startswith("Operation"):
                operation = Operation(content.split("=")[1].strip())
            elif content.startswith("Test"):
                test_divisor = content.split(" ")[-1]
            elif content.startswith("If true"):
                target_true = content.split(" ")[-1]
            elif content.startswith("If false"):
                target_false = content.split(" ")[-1]
                condition = Condition(divisor=test_divisor, target_true=target_true, target_false=target_false)
                monkeys.append(Monkey(items, operation, condition))
                global_modulus *= int(test_divisor)
    for monkey in monkeys:
        monkey.set_global_modulus(global_modulus)
    return monkeys
