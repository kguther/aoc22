from comparison import Ordering
from dividers import read_packet_list, get_decoder_key
from pairs import read_packet_pairs


def main():
    filename = "input"
    packet_pairs = read_packet_pairs(filename)
    correct_index_sum = 0
    for i in range(len(packet_pairs)):
        ordering = packet_pairs[i].is_ordered()
        if ordering == Ordering.correct:
            correct_index_sum += (i+1)
    print(correct_index_sum)
    packet_list = read_packet_list(filename)
    print(get_decoder_key(packet_list))


if __name__ == "__main__":
    main()