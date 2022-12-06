EOP_LENGTH = 4
SOM_LENGTH = 14

def read_line(filename):
    with open(filename) as ifile:
        return ifile.read()

def is_eop_marker(char_array):
    return len(set(char_array)) == len(char_array)

def find_sop_marker(feed, marker_length):
    for slice_start in range(len(feed)-marker_length):
        if is_eop_marker(feed[slice_start:slice_start+marker_length]):
            return slice_start + marker_length
    return 0

def main():
    line = read_line("input")
    print(find_sop_marker(line, EOP_LENGTH))
    print(find_sop_marker(line, SOM_LENGTH))

if __name__ == "__main__":
    main()
