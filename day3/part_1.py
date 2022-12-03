from rucksack import read_items


def main():
    rucksacks = read_items("input")
    duplicates = [rucksack.duplicate_priorities() for rucksack in rucksacks]
    print(sum(duplicates))


if __name__ == "__main__":
    main()
