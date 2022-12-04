/*
 * AssignmentPair.cpp
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#include "AssignmentPair.h"
#include "SplitString.h"

AssignmentPair AssignmentPair::from_string(std::string const &input){
	auto parts = split_string(input, ',');
	return AssignmentPair(RangeAssignment::from_string(std::get<0>(parts)), RangeAssignment::from_string(std::get<1>(parts)));
}

bool AssignmentPair::is_redundant() const {
	return apply_both([](RangeAssignment const &first, RangeAssignment const &second){return first.contains(second);});
}

bool AssignmentPair::is_overlapping() const {
	return apply_both([](RangeAssignment const &first, RangeAssignment const &second){return first.overlaps(second);});
}
