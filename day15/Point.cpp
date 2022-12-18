/*
 * Point.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#include <cstdlib>
#include "SplitString.h"
#include "Point.h"

int Point::distance(Point const &other) const{
	return std::abs(x_coord - other.x_coord) + std::abs(y_coord - other.y_coord);
}

Point Point::from_string(std::string const &p_str){
	auto parts = split_string(p_str, ',');
	auto x_coord = std::get<1>(split_string(std::get<0>(parts), '='));
	auto y_coord = std::get<1>(split_string(std::get<1>(parts), '='));
	return Point(std::stoi(x_coord), std::stoi(y_coord));
}
