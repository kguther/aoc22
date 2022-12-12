/*
 * GridCrawler.h
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#ifndef GRIDCRAWLER_H_
#define GRIDCRAWLER_H_

#include "HeightMap.h"
#include "PathMap.h"
#include "UnvisitedPoints.h"

class GridCrawler {
public:
	GridCrawler(HeightMap const &height_map_);
	virtual ~GridCrawler() {};

	PathMap iterate();
	void perform_iteration();
private:
	Point current, target;
	UnvisitedPoints unvisited_points;
	PathMap path_lengths;
};

#endif /* GRIDCRAWLER_H_ */
