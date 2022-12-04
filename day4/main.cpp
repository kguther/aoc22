/*
 * main.cpp
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#include <iostream>
#include "Schedule.h"


int main(int argc, char *argv[]){
	auto schedule = Schedule::from_file("input");
	std::cout << "Number of redundant pairs: " << schedule.n_redundant_pairs() << std::endl;
	std::cout << "Number of overlapping pairs: " << schedule.n_overlapping_pairs() << std::endl;
}



