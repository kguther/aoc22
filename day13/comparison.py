from enum import Enum


class Ordering(Enum):
    correct = -1
    incorrect = 1
    undecided = 0


def compare(packet_one, packet_two):
    if isinstance(packet_one, int):
        if isinstance(packet_two, int):
            if packet_one < packet_two:
                return Ordering.correct
            elif packet_one > packet_two:
                return Ordering.incorrect
            return Ordering.undecided
        return compare([packet_one], packet_two)
    elif isinstance(packet_two, int):
        return compare(packet_one, [packet_two])
    return list_compare(packet_one, packet_two)


def list_compare(packet_one, packet_two):
    comparable_range = range(min(len(packet_one), len(packet_two)))
    for i in comparable_range:
        result = compare(packet_one[i], packet_two[i])
        if result != Ordering.undecided:
            return result
    if len(packet_one) < len(packet_two):
        return Ordering.correct
    if len(packet_one) > len(packet_two):
        return Ordering.incorrect
    return Ordering.undecided
