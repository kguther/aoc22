from cave import read_cave


def main():
    cave = read_cave("input")
    cave.fill()
    print(cave.sand_amount)


if __name__ == "__main__":
    main()
