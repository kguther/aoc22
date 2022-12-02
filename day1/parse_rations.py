def read_list(filename):
    elves = []
    current_elf_rations = []
    with open(filename) as ip:
        for line in ip:
            line_stripped = line.strip()
            if line_stripped:
                current_elf_rations.append(int(line_stripped))
            else:
                elves.append(current_elf_rations)
                current_elf_rations = []
    elves.append(current_elf_rations)
    return elves


def get_calories_per_elf(elves):
    return [sum(elf) for elf in elves]

def get_top_calories(calories_per_elf, num_tops):
    sorted_calories = sorted(calories_per_elf, reverse=True)
    return sum(sorted_calories[:num_tops])

def main():
    elves = read_list("input")
    calories_per_elf = get_calories_per_elf(elves)
    print(max(calories_per_elf))
    print(get_top_calories(calories_per_elf, 3))

if __name__ == "__main__":
    main()


