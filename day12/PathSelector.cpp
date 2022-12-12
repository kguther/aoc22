/*
 * PathSelector.cpp
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#include <algorithm>
#include "PathSelector.h"

std::vector<int> PathSelector::path_lengths(int target_elevation) const {
	auto height_map = path_map.get_height_map();
	std::vector<int> length_values;

	for(auto x: height_map.points()){
		if(height_map.height(x) == target_elevation){
			length_values.push_back(path_map.path_length(x));
		}
	}
	return length_values;
}

int PathSelector::min_path_length(int target_elevation) const {
	auto lengths = path_lengths(target_elevation);
	return *std::min_element(lengths.begin(), lengths.end());
}
