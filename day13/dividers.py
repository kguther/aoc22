from functools import cmp_to_key

from pairs import cmp_pairs

DIVIDER_PACKETS = [[[2]], [[6]]]


def read_packet_list(filename):
    with open(filename) as ifile:
        packets = [eval(line.strip()) for line in ifile if line.strip() != ""]
        return packets + DIVIDER_PACKETS


def get_decoder_key(packet_list):
    sorted_packets = sorted(packet_list, key=cmp_to_key(cmp_pairs))
    decoder_key = 1
    for package in DIVIDER_PACKETS:
        decoder_key *= (sorted_packets.index(package)+1)
    return decoder_key
