/*
 * AssignmentPair.h
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#ifndef ASSIGNMENTPAIR_H_
#define ASSIGNMENTPAIR_H_

#include "RangeAssignment.h"
#include <string>

class AssignmentPair {
public:
	AssignmentPair() {};
	AssignmentPair(RangeAssignment const &first_, RangeAssignment const &second_): first(first_), second(second_){};
	virtual ~AssignmentPair() {};

	bool is_redundant() const;
	bool is_overlapping() const;

	static AssignmentPair from_string(std::string const &input);
private:
	RangeAssignment first, second;
	template<typename T>
	bool apply_both(T const& operation) const {
		return operation(first, second) || operation(second, first);
	}
};

#endif /* ASSIGNMENTPAIR_H_ */
