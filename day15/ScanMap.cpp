/*
 * ScanMap.cpp
 *
 *  Created on: Dec 18, 2022
 *      Author: kai
 */

#include <fstream>
#include <algorithm>
#include <functional>
#include "ScanMap.h"

ScanMap::ScanMap(std::vector<Scanner> const &scanners_): scanners(scanners_){
	std::vector<int> tmp(scanners.size());
	std::transform(scanners.begin(), scanners.end(), tmp.begin(), std::mem_fn(&Scanner::min_x));
	min_x = *std::min_element(tmp.begin(), tmp.end());
	std::transform(scanners.begin(), scanners.end(), tmp.begin(), std::mem_fn(&Scanner::max_x));
	max_x = *std::max_element(tmp.begin(), tmp.end());
}

int ScanMap::coverage(int line_number) const {
	Point probe;
	int coverage_count = 0;
	for(int x_coord = min_x; x_coord <= max_x; ++x_coord){
		probe = Point(x_coord, line_number);
		for(auto &scanner: scanners){
			if(scanner.excludes(probe)){
				++coverage_count;
				break;
			}
		}
	}
	return coverage_count;
}

ScanMap ScanMap::from_file(std::string const &filename) {
	std::ifstream inputfile(filename);
	std::string line;
	std::vector<Scanner> scanners_;
	for(std::string line; std::getline(inputfile, line);){
		scanners_.push_back(Scanner::from_line(line));
	}
	return ScanMap(scanners_);
}

Point ScanMap::find_beacon(int limits) const {
	int x_coord = 0;
	int y_coord = 0;
	Point probe(x_coord, y_coord);
	Point original_probe = probe;
	do{
		original_probe = probe;
		for(auto &scanner: scanners){
			if(scanner.covers(probe)){
				probe = scanner.mirror(probe, limits);
			}
		}
	} while(original_probe != probe);
	return probe;
}
