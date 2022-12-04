/*
 * RangeAssignment.cpp
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#include "RangeAssignment.h"
#include "SplitString.h"
#include <stdexcept>

RangeAssignment::RangeAssignment(int start_, int end_): start(start_), end(end_) {
	if(start > end){
		throw std::domain_error("Cannot start after end.");
	}
}

bool RangeAssignment::contains(RangeAssignment const &other) const{
	return other.start >= start && other.end <= end;
}

bool RangeAssignment::overlaps(RangeAssignment const &other) const{
	return contains(RangeAssignment(other.start, other.start)) || contains(RangeAssignment(other.end, other.end));
}

RangeAssignment RangeAssignment::from_string(std::string const& input){
	auto parts = split_string(input, '-');
	return RangeAssignment(std::stoi(std::get<0>(parts)), std::stoi(std::get<1>(parts)));
}
