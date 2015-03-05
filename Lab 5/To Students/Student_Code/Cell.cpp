/*
 * Cell.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Jason
 */

#include "Cell.h"

namespace std {

Cell::Cell() {

}

Cell::Cell(int x, int y, int z) {

}

void Cell::setCoordinate(int x, int y, int z) {
	coordinate.x = x;
	coordinate.y = y;
	coordinate.z = z;
}

void Cell::setTraversable(bool b) {
	traversable = b;
}

bool Cell::isTraversable() {
	return traversable;
}

void Cell::setDeadEnd(bool b) {
	deadEnd = b;
}
bool Cell::isDeadEnd() {
	return deadEnd;
}

void Cell::setExhausted(bool b) {
	exhausted = b;
}
bool Cell::isExhausted() {
	return exhausted;
}

void Cell::setSolution(bool b) {
	solution = b;
}
bool Cell::isSolution() {
	return solution;
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
