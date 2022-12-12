/*
 * main.cpp
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#include <iostream>

#include "HeightMap.h"
#include "GridCrawler.h"
#include "PathSelector.h"

int main(int argc, char *argv[]){
	auto height_map = map_from_file("input");
	GridCrawler crawler(height_map);
	auto path_weights = crawler.iterate();
	PathSelector path_selector(path_weights);
	std::cout << "Shortest path has length " << path_selector.min_path_length(int('a')) << std::endl;
}


