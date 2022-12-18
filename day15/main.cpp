/*
 * main.cpp
 *
 *  Created on: Dec 18, 2022
 *      Author: kai
 */

#include <iostream>
#include "ScanMap.h"

int main(int argc, char *argv[]){
	auto scan_map = ScanMap::from_file("input");
	//std::cout << scan_map.coverage(10) << std::endl;
	auto beacon = scan_map.find_beacon(4000000);
	//auto beacon = scan_map.find_beacon(20);
	std::cout << beacon.tuning_frequency() << std::endl;
}

