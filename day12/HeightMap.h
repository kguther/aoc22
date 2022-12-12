/*
 * HeightMap.h
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#ifndef HEIGHTMAP_H_
#define HEIGHTMAP_H_

#include <string>

#include "Array.h"
#include "IntMap.h"
#include "Point.h"


class HeightMap {
public:
	HeightMap(Array<int> const &map_);
	HeightMap() {max_distance = 0; target_position = Point();};
	virtual ~HeightMap() {};
	int height(Point const &x) const {return map.value(x);}
	int distance(Point const & start,Point const &end);
	int size_x() const {return map.size_x();}
	int size_y() const {return map.size_y();}
	Point target() const {return target_position;}
	Point start() const {return start_position;}
	std::vector<Point> points() const;
	bool is_on_map(Point const &x) const {return x.x() >= 0 && x.y() >= 0 && x.x() < size_x() && x.y() < size_y();}
private:
	IntMap map;
	Point target_position, start_position;
	int max_distance;
};

HeightMap map_from_file(std::string filename);
HeightMap extended_map_from_file(std::string filename);

#endif /* HEIGHTMAP_H_ */
