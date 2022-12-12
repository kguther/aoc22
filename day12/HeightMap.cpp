/*
 * HeightMap.cpp
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#include <fstream>
#include <cstdlib>

#include "HeightMap.h"

HeightMap::HeightMap(Array<int> const &map_): map(map_){
	max_distance = 100 * map.size_x() * map.size_y();
	for(auto x: points()){
		if(height(x) == int('E')){
			map.set_value(x, int('z'));
			target_position = x;
		}
		if(height(x) == int('S')){
			map.set_value(x, int('a'));
			start_position = x;
		}
	}
}


std::vector<Point> HeightMap::points() const{
	std::vector<Point> points_of_map(0);
	for(int x=0; x < size_x(); ++x){
		for(int y=0; y < size_y(); ++y){
			points_of_map.push_back(Point(x,y));
		}
	}
	return points_of_map;
}


int HeightMap::distance(Point const &start, Point const &end) {
	if(height(start) - height(end) <= 1){
		return 1;
	}
	return max_distance;
}

std::vector<int> line_as_ints(std::string const &string){
	std::vector<int> row(0);
	for(auto x: string){
		row.push_back(int(x));
	}
	return row;
}

Array<int> array_from_file(const std::string &filename) {
	std::ifstream inputfile(filename);
	std::string line;
	Array<int> map;
	while (inputfile >> line) {
		map.push_back(line_as_ints(line));
	}
	return map;
}

HeightMap map_from_file(std::string filename){
	auto map = array_from_file(filename);
	return HeightMap(map);
}

