/*
 * PathSelector.h
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#ifndef PATHSELECTOR_H_
#define PATHSELECTOR_H_

#include <vector>
#include "PathMap.h"

class PathSelector {
public:
	PathSelector(PathMap const &path_map_): path_map(path_map_){};
	virtual ~PathSelector() {};
	std::vector<int> path_lengths(int target_elevation) const;
	int min_path_length(int target_elevation) const;
private:
	PathMap path_map;
};

#endif /* PATHSELECTOR_H_ */
