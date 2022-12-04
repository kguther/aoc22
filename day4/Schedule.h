/*
 * Schedule.h
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "RangeAssignment.h"
#include "AssignmentPair.h"
#include <vector>
#include <string>

class Schedule {
public:
	Schedule();
	virtual ~Schedule() {};

	int n_redundant_pairs() const;
	int n_overlapping_pairs() const;

	static Schedule from_file(std::string const &filename);
private:
	std::vector<AssignmentPair> assignments;
	void add(AssignmentPair const &assignment_pair);

	template<typename T>
	int count_pairs(T const& criterium) const {
		int n = 0;
		for(auto pair: assignments){
			if(criterium(pair)){
				n++;
			}
		}
		return n;
	}
};


#endif /* SCHEDULE_H_ */
