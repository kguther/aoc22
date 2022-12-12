/*
 * PathMap.h
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#ifndef PATHMAP_H_
#define PATHMAP_H_

#include <limits>
#include "HeightMap.h"
#include "UnvisitedPoints.h"

class PathMap {
public:
	PathMap(HeightMap const &risk_map_, UnvisitedPoints const &unvisited_, Point const &initial);
	virtual ~PathMap() {};
	int path_length(Point const &x) const {return path_lengths.value(x);}
	void set_path_length(Point const &x, int value) {path_lengths.set_value(x, value);}
	void evaluate_path_lengths(Point const &pos);
	Point closest_unvisited_point() const;
	HeightMap get_height_map() const {return height_map;}
private:
	HeightMap height_map;
	IntMap path_lengths;
	UnvisitedPoints const& unvisited;
};

#endif /* PATHMAP_H_ */
