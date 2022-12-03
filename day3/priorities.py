import string


def priority(item):
    if item == item.upper():
        offset = 27
    else:
        offset = 1
    return offset + string.ascii_lowercase.find(item.lower())


def duplicate_priorities(rucksack):
    duplicates = rucksack.duplicate_items()
    return sum(priority(item) for item in duplicates)
