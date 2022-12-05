/*
 * Supplies.cpp
 *
 *  Created on: Dec 5, 2022
 *      Author: kai
 */

#include "Supplies.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void read_stacks(std::string const &line, std::vector<Stack> &stacks);

void Supplies::get_top_crates() const {
	std::cout << "Top crates contain: ";
	for(auto &stack: stacks){
		std::cout << stack.back();
	}
	std::cout << std::endl;
}

Supplies Supplies::from_file(const std::string &filename) {
	std::ifstream inputfile(filename);
	std::string line;
	std::getline(inputfile, line);
	std::vector<Stack> stacks((line.length() + 1) / 4);
	read_stacks(line, stacks);
	while(true){
		inputfile >> std::ws;
		std::getline(inputfile, line);
		if(line[1] == '1'){
			break;
		}
		read_stacks(line, stacks);
	}
	for(auto &stack: stacks){
		std::reverse(stack.begin(), stack.end());
	}
	return Supplies(stacks);
}

void Supplies::apply_v1(const Instruction &instruction) {
	auto &source_stack = stacks[instruction.get_src()];
	auto &target_stack = stacks[instruction.get_tgt()];
	for(int i = 0; i < instruction.get_count(); ++i){
		target_stack.push_back(source_stack.back());
		source_stack.pop_back();
	}
}

void Supplies::apply_v2(const Instruction &instruction) {
	auto &source_stack = stacks[instruction.get_src()];
	auto &target_stack = stacks[instruction.get_tgt()];
	auto start_it = source_stack.end() - instruction.get_count();
	auto end_it = source_stack.end();
	target_stack.insert(target_stack.end(), start_it, end_it);
	source_stack.erase(start_it, end_it);
}


void Supplies::apply(const InstructionSet &instructions) {
	for(auto instruction: instructions){
		apply_v2(instruction);
	}
}

void read_stacks(std::string const &line, std::vector<Stack> &stacks){
	int crate_pos;
	for(size_t i = 0; i < stacks.size(); ++i){
		crate_pos = 4*i + 1;
		auto crate = line[crate_pos];
		if(crate != ' '){
			stacks[i].push_back(crate);
		}
	}
}
