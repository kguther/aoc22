from cpu import CPU
from crt import CRT
from instruction import read_instructions


def main():
    instructions = read_instructions("input")
    crt = CRT()
    cpu = CPU(crt)
    for instruction in instructions:
        cpu.apply_instruction(instruction)
    print(cpu.signal)
    crt.draw()


if __name__ == "__main__":
    main()