from elf_group import read_groups


def main():
    elf_groups = read_groups("input")
    badge_priorities = [elf_group.badge_priority() for elf_group in elf_groups]
    print(sum(badge_priorities))


if __name__ == "__main__":
    main()
