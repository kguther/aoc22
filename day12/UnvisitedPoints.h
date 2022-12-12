/*
 * UnvisitedPoints.h
 *
 *  Created on: Dec 15, 2021
 *      Author: kai
 */

#ifndef UNVISITEDPOINTS_H_
#define UNVISITEDPOINTS_H_

#include "HeightMap.h"

class UnvisitedPoints {
public:
	UnvisitedPoints(HeightMap const &risk_map, Point const &initial);
	virtual ~UnvisitedPoints() {};
	void remove_point(Point const &point);
	bool is_unvisited(Point const &point) const;
	size_t size() const {return unvisited.size();}
	std::vector<Point> points() const {return unvisited;}
private:
	std::vector<Point> unvisited;
};

#endif /* UNVISITEDPOINTS_H_ */
