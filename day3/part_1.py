from priorities import duplicate_priorities
from rucksack import read_items


def main():
    rucksacks = read_items("input")
    duplicates = [duplicate_priorities(rucksack) for rucksack in rucksacks]
    print(sum(duplicates))


if __name__ == "__main__":
    main()
