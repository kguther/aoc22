/*
 * GridCrawler.cpp
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#include "GridCrawler.h"

GridCrawler::GridCrawler(HeightMap const &height_map_): current(height_map_.target()), unvisited_points(height_map_, current), path_lengths(height_map_, unvisited_points, current) {
	target = height_map_.target();
}

PathMap GridCrawler::iterate(){
	while(unvisited_points.size()>0){
		perform_iteration();
	}
	return path_lengths;
}

void GridCrawler::perform_iteration(){
	path_lengths.evaluate_path_lengths(current);
	current = path_lengths.closest_unvisited_point();
	unvisited_points.remove_point(current);
}
