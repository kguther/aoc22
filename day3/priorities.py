import string


def priority(item):
    if item == item.upper():
        offset = 27
    else:
        offset = 1
    return offset + string.ascii_lowercase.find(item.lower())


