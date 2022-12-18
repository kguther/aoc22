/*
 * Point.h
 *
 *  Created on: Dec 9, 2021
 *      Author: kai
 */

#ifndef PART_1_POINT_H_
#define PART_1_POINT_H_

#include <string>

class Point {
public:
	Point(): x_coord(0), y_coord(0) {};
	Point(int x, int y): x_coord(x), y_coord(y) {};
	virtual ~Point() {};
	int x() const {return x_coord;}
	int y() const {return y_coord;}
	int distance(Point const &other) const;
	long tuning_frequency() const {return static_cast<long>(x_coord) * 4000000l + static_cast<long>(y_coord);}

	static Point from_string(std::string const &p_str);
private:
	int x_coord;
	int y_coord;
};

inline bool operator==(Point const &a, Point const &b){
	return a.x() == b.x() && a.y() == b.y();
}

inline bool operator!=(Point const &a, Point const &b){
	return not (a==b);
}

#endif /* PART_1_POINT_H_ */
