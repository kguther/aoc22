from instruction import read_instructions
from rope import Rope


def main():
    rope = Rope(10)
    instructions = read_instructions("input")
    for instruction in instructions:
        rope.apply(instruction)
    print(rope.path_length())

if __name__ == "__main__":
    main()