/*
 * RangeAssignment.h
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#ifndef RANGEASSIGNMENT_H_
#define RANGEASSIGNMENT_H_

#include <string>

class RangeAssignment {
public:
	RangeAssignment(): start(0), end(0) {};
	RangeAssignment(int start_, int end_);
	virtual ~RangeAssignment() {};

	bool contains(RangeAssignment const &other) const;
	bool overlaps(RangeAssignment const &other) const;

	static RangeAssignment from_string(std::string const& input);
private:
	int start;
	int end;
};

#endif /* RANGEASSIGNMENT_H_ */
