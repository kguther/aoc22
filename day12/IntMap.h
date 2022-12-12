/*
 * IntMap.h
 *
 *  Created on: Dec 12, 2022
 *      Author: kai
 */

#ifndef INTMAP_H_
#define INTMAP_H_

#include "Array.h"
#include "Point.h"

class IntMap {
public:
	IntMap(Array<int> const& map_): map(map_) {};
	IntMap() {};
	virtual ~IntMap() {};
	int value(Point const &x) const {return map[x.x()][x.y()];}
	void set_value(Point const &x, int value) {map[x.x()][x.y()] = value;}
	int size_x() const {return map.size();}
	int size_y() const {return map[0].size();}
private:
	Array<int> map;
};


#endif /* INTMAP_H_ */
