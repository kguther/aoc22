/*
 * Scanner.cpp
 *
 *  Created on: Dec 18, 2022
 *      Author: kai
 */

#include "Scanner.h"
#include "SplitString.h"
#include <cstdlib>


Scanner Scanner::from_line(std::string const &line) {
	auto parts = split_string(line, ':');
	Point pos_ = Point::from_string(std::get<0>(parts));
	Point beacon_ = Point::from_string(std::get<1>(parts));
	return Scanner(pos_, beacon_);
}


bool Scanner::covers(Point const &p) const {
	return pos.distance(p) <= covering_range;
}

bool Scanner::excludes(Point const &p) const {
	return covers(p) and p != beacon;
}

int Scanner::min_x() const {
	return pos.x() - covering_range;
}

int Scanner::max_x() const {
	return pos.x() + covering_range;
}

Point Scanner::mirror(const Point &p, int limits) const {
	int y_distance = std::abs(p.y() - pos.y());
	int x_limit = pos.x() + covering_range - y_distance + 1;
	if(x_limit > limits){
		return Point(0, p.y()+1);
	}
	return Point(x_limit, p.y());
}
