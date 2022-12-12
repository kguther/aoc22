/*
 * PathMap.cpp
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#include <vector>
#include "Array.h"
#include "PathMap.h"

int MAX_WEIGHT = std::numeric_limits<int>::max();

PathMap::PathMap(const HeightMap &risk_map_, UnvisitedPoints const &unvisited_, Point const &initial): height_map(risk_map_), unvisited(unvisited_) {
	Array<int> path_risk_values(height_map.size_x(), std::vector<int>(height_map.size_y(), MAX_WEIGHT));
	path_lengths = IntMap(path_risk_values);
	path_lengths.set_value(initial, 0);
}

void PathMap::evaluate_path_lengths(const Point &pos) {
	auto adjacents = pos.adjacent_points();
	int path_length, new_length;
	for(auto point: adjacents){
		if(unvisited.is_unvisited(point) && height_map.is_on_map(point)){
			path_length = path_lengths.value(point);
			new_length = path_lengths.value(pos) + height_map.distance(pos, point);
			if(new_length < path_length){
				path_lengths.set_value(point, new_length);
			}
		}
	}
}

Point PathMap::closest_unvisited_point() const {
	auto unvisited_points = unvisited.points();
	Point least_risky_point = unvisited_points[0];
	for(auto point: unvisited_points){
		if(path_lengths.value(point) < path_lengths.value(least_risky_point)){
			least_risky_point = point;
		}
	}
	return least_risky_point;
}
