/*
 * Supplies.h
 *
 *  Created on: Dec 5, 2022
 *      Author: kai
 */

#ifndef SUPPLIES_H_
#define SUPPLIES_H_

#include "Stack.h"
#include "Instruction.h"
#include <vector>
#include <string>

class Supplies {
public:
	Supplies(std::vector<Stack> const &stacks_): stacks(stacks_) {};
	virtual ~Supplies() {};

	void apply_v1(Instruction const &instruction);
	void apply_v2(Instruction const &instruction);
	void apply(const InstructionSet &instructions);

	void get_top_crates() const;

	static Supplies from_file(std::string const &filename);
private:
	std::vector<Stack> stacks;
};

#endif /* SUPPLIES_H_ */
