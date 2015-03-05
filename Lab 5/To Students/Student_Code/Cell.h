/*
 * Cell.h
 *
 *  Created on: Feb 26, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_CELL_H_
#define TO_STUDENTS_STUDENT_CODE_CELL_H_

namespace std {

struct Coordinate{

	Coordinate(){
		x = 0;
		y = 0;
		z = 0;
	}
	Coordinate(int x, int y, int z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int x, y, z;

};

class Cell {
public:
	Cell();
	Cell(int x, int y, int z);
	virtual ~Cell();

	void setTraversable(bool b);
	bool isTraversable();

	void setDeadEnd(bool b);
	bool isDeadEnd();

	void setExhausted(bool b);
	bool isExhausted();

	void setSolution(bool b);
	bool isSolution();

	void setCoordinate(int x, int y, int z);

	Coordinate coordinate;
private:
	bool traversable = false, deadEnd = false, exhausted = false, solution = false;
};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_CELL_H_ */
