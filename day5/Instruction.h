/*
 * Instruction.h
 *
 *  Created on: Dec 5, 2022
 *      Author: kai
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>
#include <vector>

class Instruction {
public:
	Instruction(int src_, int tgt_, int count_): src(src_), tgt(tgt_), count(count_) {};
	virtual ~Instruction() {};

	static Instruction from_string(std::string const &input);

	int get_count() const {
		return count;
	}

	int get_src() const {
		return src;
	}

	int get_tgt() const {
		return tgt;
	}

private:
	int src, tgt, count;
};

using InstructionSet = std::vector<Instruction>;

InstructionSet read_instructions(std::string const &filename);

#endif /* INSTRUCTION_H_ */
