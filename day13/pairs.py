from dataclasses import dataclass

from comparison import Ordering, compare

@dataclass
class PacketPair:
    first: list
    second: list

    def is_ordered(self) -> Ordering:
        return compare(self.first, self.second)


def cmp_pairs(first, second):
    return compare(first, second).value


def read_packet_pairs(filename):
    packets = []
    with open(filename) as ifile:
        lines = ifile.readlines()
        for i in range(0, len(lines), 3):
            first_packet = eval(lines[i].strip())
            second_packet = eval(lines[i+1].strip())
            packets.append(PacketPair(first_packet, second_packet))

    return packets
