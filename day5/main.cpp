/*
 * main.cpp
 *
 *  Created on: Dec 5, 2022
 *      Author: kai
 */

#include "Supplies.h"
#include "Instruction.h"

int main(int argc, char *argv[]){
	std::string filename = "input";
	Supplies supplies = Supplies::from_file(filename);
	InstructionSet instructions = read_instructions(filename);
	supplies.apply(instructions);
	supplies.get_top_crates();
}


