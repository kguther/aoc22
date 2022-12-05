/*
 * Instruction.cpp
 *
 *  Created on: Dec 5, 2022
 *      Author: kai
 */

#include "Instruction.h"
#include <sstream>
#include <fstream>

Instruction Instruction::from_string(const std::string &input) {
	std::istringstream parse(input);
	std::string buf;
	int src, tgt, count;
	parse >> buf;
	parse >> count;
	parse >> buf;
	parse >> src;
	parse >> buf;
	parse >> tgt;
	return Instruction(src-1, tgt-1, count);
}

InstructionSet read_instructions(const std::string &filename) {
	std::vector<Instruction> instructions;
	std::ifstream inputfile(filename);
	for(std::string line; std::getline(inputfile, line);){
		if(line[0] == 'm'){
			instructions.push_back(Instruction::from_string(line));
		}
	}
	return instructions;
}
