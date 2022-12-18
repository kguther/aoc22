/*
 * Scanner.h
 *
 *  Created on: Dec 18, 2022
 *      Author: kai
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include "Point.h"

class Scanner {
public:
	Scanner(Point const &pos_, Point const &beacon_): pos(pos_), beacon(beacon_) {covering_range = pos.distance(beacon);};
	virtual ~Scanner() {};

	bool covers(Point const &p) const;
	bool excludes(Point const &p) const;
	Point mirror(Point const &p, int limits) const;
	int min_x() const;
	int max_x() const;

	static Scanner from_line(std::string const &line);
private:
	Point pos, beacon;
	int covering_range;
};

#endif /* SCANNER_H_ */
