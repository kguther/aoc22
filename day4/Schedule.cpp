/*
 * Schedule.cpp
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#include "Schedule.h"
#include <fstream>

Schedule::Schedule(){
	assignments = std::vector<AssignmentPair>();
}

int Schedule::n_redundant_pairs() const {
	return count_pairs([](AssignmentPair const &pair){return pair.is_redundant();});
}

int Schedule::n_overlapping_pairs() const {
	return count_pairs([](AssignmentPair const &pair){return pair.is_overlapping();});
}

void Schedule::add(AssignmentPair const &assignment_pair){
	assignments.push_back(assignment_pair);
}

Schedule Schedule::from_file(std::string const &filename){
	std::ifstream inputfile(filename);
	std::string line;
	Schedule schedule;
	while(inputfile >> line){
		auto current_pair = AssignmentPair::from_string(line);
		schedule.add(current_pair);
	}
	return schedule;
}

