/*
 * Pathfinder.h
 *
 *  Created on: Feb 26, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_PATHFINDER_H_
#define TO_STUDENTS_STUDENT_CODE_PATHFINDER_H_

#include "PathfinderInterface.h"
#include "Cell.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace std {

struct Maze {
	int xDepth = 5, yDepth = 5, zDepth = 5;
	Cell cells[5][5][5];

	void operator=(Maze &maze);
};

class Pathfinder: public PathfinderInterface {
public:
	Pathfinder();
	virtual ~Pathfinder();

	string getMaze();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();

	void printCurrentMaze();
	void clearCurrentMaze();

	bool canTurnLeft(Coordinate c);
	bool canTurnRight(Coordinate c);
	bool canTurnUp(Coordinate c);
	bool canTurnDown(Coordinate c);
	bool canTurnFront(Coordinate c);
	bool canTurnBack(Coordinate c);
	bool cannotTurn(Coordinate c);

	bool turnLeft(Coordinate c, vector<string> &solutionPath);
	bool turnRight(Coordinate c, vector<string> &solutionPath);
	bool turnUp(Coordinate c, vector<string> &solutionPath);
	bool turnDown(Coordinate c, vector<string> &solutionPath);
	bool turnFront(Coordinate c, vector<string> &solutionPath);
	bool turnBack(Coordinate c, vector<string> &solutionPath);

	bool solveCurrentPath(Coordinate c, vector<string> &solutionPath);
	void restartCurrentMaze();

	Cell* currentCell(Coordinate c);

	string stringFromCoordinat(Coordinate c);

private:
	vector<Cell> traversableCells();
	vector<Cell> traversedCells();
	vector<Cell> deadEndCells();
	vector<Cell> solutionCells();

	Maze currentMaze;


};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_PATHFINDER_H_ */
