from parser import read_monkeys


def run_round(monkeys):
    for monkey in monkeys:
        monkey.check_items(monkeys)

def main():
    monkeys = read_monkeys("input")
    for i in range(10000):
        run_round(monkeys)
    activity_levels = [monkey.inspected_items for monkey in monkeys]
    activity_levels.sort(reverse=True)
    print(activity_levels)
    print(activity_levels[0]*activity_levels[1])


if __name__ == "__main__":
    main()