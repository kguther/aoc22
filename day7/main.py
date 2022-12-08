from parser import Parser


def subdir_sizes_below_limit(dir, limit):
    subdirs = dir.all_subdirs()
    subdir_sizes = [subdir.size() for subdir in subdirs]
    return sum(subdir_size for subdir_size in subdir_sizes if subdir_size < limit)


def largest_subdir_above_limit(dir, limit):
    subdirs = dir.all_subdirs()
    subdir_sizes = [subdir.size() for subdir in subdirs]
    return min(subdir_size for subdir_size in subdir_sizes if subdir_size > limit)


def required_space(dir, max_space, total_required):
    return total_required - (max_space - dir.size())


def main():
    parser = Parser()
    root = parser.read_directory("input")
    print(subdir_sizes_below_limit(root, 100000))
    required = required_space(root, 70000000, 30000000)
    print(largest_subdir_above_limit(root, required))

if __name__ == "__main__":
    main()