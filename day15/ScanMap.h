/*
 * ScanMap.h
 *
 *  Created on: Dec 18, 2022
 *      Author: kai
 */

#ifndef SCANMAP_H_
#define SCANMAP_H_

#include <vector>
#include <string>
#include "Scanner.h"

class ScanMap {
public:
	ScanMap(std::vector<Scanner> const &scanners_);
	virtual ~ScanMap() {};

	int coverage(int line_number) const;
	Point find_beacon(int limits) const;

	static ScanMap from_file(std::string const &filename);
private:
	std::vector<Scanner> scanners;
	int min_x, max_x;
};

#endif /* SCANMAP_H_ */
