/*
 * Pathfinder.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Jason
 */

#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder() {
	clearCurrentMaze();
}

void Pathfinder::printCurrentMaze() {
}

void Pathfinder::clearCurrentMaze() {
	for (int zLayer = 0; zLayer < currentMaze.zDepth; zLayer++) {
		for (int yLayer = 0; yLayer < currentMaze.yDepth; yLayer++) {
			for (int xLayer = 0; xLayer < currentMaze.xDepth; xLayer++) {
				currentMaze.cells[xLayer][yLayer][zLayer].setTraversable(true);
			}
		}
	}
}

void Maze::operator =(Maze &maze) {
	for (int zLayer = 0; zLayer < maze.zDepth; zLayer++) {
		for (int yLayer = 0; yLayer < maze.yDepth; yLayer++) {
			for (int xLayer = 0; xLayer < maze.xDepth; xLayer++) {
				this->cells[xLayer][yLayer][zLayer].setTraversable(
						maze.cells[xLayer][yLayer][zLayer].isTraversable());
			}
		}
	}
}

string Pathfinder::getMaze() {
	string result;
	for (int zLayer = 0; zLayer < currentMaze.zDepth; zLayer++) {
		for (int yLayer = 0; yLayer < currentMaze.yDepth; yLayer++) {
			for (int xLayer = 0; xLayer < currentMaze.xDepth; xLayer++) {
				if (xLayer > 0) {
					result += " ";
				}
				if (currentMaze.cells[xLayer][yLayer][zLayer].isTraversable()) {
					result += "1";
				} else {
					result += "0";
				}
			}
			result += "\n";
		}
		result += "\n";
	}
	return result;
}

void Pathfinder::createRandomMaze() {
	for (int zLayer = 0; zLayer < currentMaze.yDepth; zLayer++) {
		for (int yLayer = 0; yLayer < currentMaze.yDepth; yLayer++) {
			for (int xLayer = 0; xLayer < currentMaze.xDepth; xLayer++) {
				currentMaze.cells[xLayer][yLayer][zLayer].setTraversable(
						rand() % 2);
			}
		}
	}
	currentMaze.cells[0][0][0].setTraversable(true);
	currentMaze.cells[4][4][4].setTraversable(true);
}

bool Pathfinder::importMaze(string file_name) {
	string name = file_name;
	ifstream fileStream;
	fileStream.open(file_name.c_str());
	int cellInt, lengthChecker = int(), ones = 0, zeros = 0;
	Maze tempMaze = currentMaze;

	for (int zLayer = 0; zLayer < currentMaze.zDepth; zLayer++) {
		for (int yLayer = 0; yLayer < currentMaze.yDepth; yLayer++) {
			for (int xLayer = 0; xLayer < currentMaze.xDepth; xLayer++) {
				cellInt = -1;
				fileStream >> cellInt;
				if (cellInt == -1) {
					currentMaze = tempMaze;
					return false;
				}
				if (cellInt == 0) {
					currentMaze.cells[xLayer][yLayer][zLayer].setCoordinate(
							xLayer, yLayer, zLayer);
					currentMaze.cells[xLayer][yLayer][zLayer].setTraversable(
							false);
					zeros++;
				} else if (cellInt == 1) {
					currentMaze.cells[xLayer][yLayer][zLayer].setCoordinate(
							xLayer, yLayer, zLayer);
					currentMaze.cells[xLayer][yLayer][zLayer].setTraversable(
							true);
					ones++;
				} else {
					currentMaze = tempMaze;
					return false;
				}
			}
		}
	}
	if (!currentMaze.cells[0][0][0].isTraversable()
			|| !currentMaze.cells[4][4][4].isTraversable()) {
		currentMaze = tempMaze;
		return false;
	}
	if (ones < 5) {
		currentMaze = tempMaze;
		return false;
	}

	fileStream >> lengthChecker;
	if (lengthChecker != int()) {
		currentMaze = tempMaze;
		return false;
	} else {
		return true;
	}
}

Cell* Pathfinder::currentCell(Coordinate c) {
	return &currentMaze.cells[c.x][c.y][c.z];
}
string Pathfinder::stringFromCoordinat(Coordinate c) {
	string result, strx, stry, strz;
	stringstream ss;

	ss << c.x;
	ss >> strx;
	ss.clear();
	ss << c.y;
	ss >> stry;
	ss.clear();
	ss << c.z;
	ss >> strz;
	ss.clear();

	result = "(" + strx + ", " + stry + ", " + strz + ")";
	return result;
}

bool Pathfinder::canTurnLeft(Coordinate c) {
	if (c.x <= 0) {
		return false;
	} else if (currentMaze.cells[c.x - 1][c.y][c.z].isExhausted()
			|| currentMaze.cells[c.x - 1][c.y][c.z].isDeadEnd()) {
		return false;
	} else if (!currentMaze.cells[c.x - 1][c.y][c.z].isTraversable()) {
		return false;
	} else {
		return true;
	}
}
bool Pathfinder::canTurnRight(Coordinate c) {
	if (c.x >= 4) {
		return false;
	} else if (currentMaze.cells[c.x + 1][c.y][c.z].isExhausted()
			|| currentMaze.cells[c.x + 1][c.y][c.z].isDeadEnd()) {
		return false;
	} else if (!currentMaze.cells[c.x + 1][c.y][c.z].isTraversable()) {
		return false;
	} else {
		return true;
	}
}
bool Pathfinder::canTurnUp(Coordinate c) {
	if (c.y <= 0) {
		return false;
	} else if (currentMaze.cells[c.x][c.y - 1][c.z].isExhausted()
			|| currentMaze.cells[c.x][c.y - 1][c.z].isDeadEnd()) {
		return false;
	} else if (!currentMaze.cells[c.x][c.y - 1][c.z].isTraversable()) {
		return false;
	} else {
		return true;
	}
}
bool Pathfinder::canTurnDown(Coordinate c) {
	if (c.y >= 4) {
		return false;
	} else if (currentMaze.cells[c.x][c.y + 1][c.z].isExhausted()
			|| currentMaze.cells[c.x][c.y + 1][c.z].isDeadEnd()) {
		return false;
	} else if (!currentMaze.cells[c.x][c.y + 1][c.z].isTraversable()) {
		return false;
	} else {
		return true;
	}
}
bool Pathfinder::canTurnFront(Coordinate c) {
	if (c.z >= 4) {
		return false;
	} else if (currentMaze.cells[c.x][c.y][c.z + 1].isExhausted()
			|| currentMaze.cells[c.x][c.y][c.z + 1].isDeadEnd()) {
		return false;
	} else if (!currentMaze.cells[c.x][c.y][c.z + 1].isTraversable()) {
		return false;
	} else {
		return true;
	}
}
bool Pathfinder::canTurnBack(Coordinate c) {
	if (c.z <= 0) {
		return false;
	} else if (currentMaze.cells[c.x][c.y][c.z - 1].isExhausted()
			|| currentMaze.cells[c.x][c.y][c.z - 1].isDeadEnd()) {
		return false;
	} else if (!currentMaze.cells[c.x][c.y][c.z - 1].isTraversable()) {
		return false;
	} else {
		return true;
	}
}
bool Pathfinder::cannotTurn(Coordinate c) {
	return (!canTurnRight(c) && !canTurnUp(c) && !canTurnDown(c)
			&& !canTurnFront(c) && !canTurnBack(c) && !canTurnLeft(c));
}

bool Pathfinder::turnLeft(Coordinate c, vector<string> &solutionPath) {
	c.x -= 1;
	if (solveCurrentPath(c, solutionPath)) {
		currentMaze.cells[c.x][c.y][c.z].setSolution(true);
		solutionPath.push_back(stringFromCoordinat(c));
		return true;
	} else {
		currentMaze.cells[c.x][c.y][c.z].setDeadEnd(true);
		return false;
	}
}
bool Pathfinder::turnRight(Coordinate c, vector<string> &solutionPath) {
	c.x += 1;
	if (solveCurrentPath(c, solutionPath)) {
		currentMaze.cells[c.x][c.y][c.z].setSolution(true);
		solutionPath.push_back(stringFromCoordinat(c));
		return true;
	} else {
		currentMaze.cells[c.x][c.y][c.z].setDeadEnd(true);
		return false;
	}
}
bool Pathfinder::turnUp(Coordinate c, vector<string> &solutionPath) {
	c.y -= 1;
	if (solveCurrentPath(c, solutionPath)) {
		currentMaze.cells[c.x][c.y][c.z].setSolution(true);
		solutionPath.push_back(stringFromCoordinat(c));
		return true;
	} else {
		currentMaze.cells[c.x][c.y][c.z].setDeadEnd(true);
		return false;
	}
}
bool Pathfinder::turnDown(Coordinate c, vector<string> &solutionPath) {
	c.y += 1;
	if (solveCurrentPath(c, solutionPath)) {
		currentMaze.cells[c.x][c.y][c.z].setSolution(true);
		solutionPath.push_back(stringFromCoordinat(c));
		return true;
	} else {
		currentMaze.cells[c.x][c.y][c.z].setDeadEnd(true);
		return false;
	}
}
bool Pathfinder::turnFront(Coordinate c, vector<string> &solutionPath) {
	c.z += 1;
	if (solveCurrentPath(c, solutionPath)) {
		currentMaze.cells[c.x][c.y][c.z].setSolution(true);
		solutionPath.push_back(stringFromCoordinat(c));
		return true;
	} else {
		currentMaze.cells[c.x][c.y][c.z].setDeadEnd(true);
		return false;
	}
}
bool Pathfinder::turnBack(Coordinate c, vector<string> &solutionPath) {
	c.z -= 1;
	if (solveCurrentPath(c, solutionPath)) {
		currentMaze.cells[c.x][c.y][c.z].setSolution(true);
		solutionPath.push_back(stringFromCoordinat(c));
		return true;
	} else {
		currentMaze.cells[c.x][c.y][c.z].setDeadEnd(true);
		return false;
	}
}

bool Pathfinder::solveCurrentPath(Coordinate c, vector<string> &solutionPath) {
	if ((c.x == 4 && c.y == 4 && c.z == 4)) {
		currentCell(c)->setSolution(true);

		return true;
	} else if (cannotTurn(c)) {
		currentCell(c)->setDeadEnd(true);
		return false;

	} else if (canTurnLeft(c)) {

		currentMaze.cells[c.x][c.y][c.z].setExhausted(true);
		if (turnLeft(c, solutionPath)) {
			currentMaze.cells[c.x][c.y][c.x].setSolution(true);
			return true;
		} else {
			currentMaze.cells[c.x][c.y][c.z].setExhausted(false);
			if (solveCurrentPath(c, solutionPath)) {
				currentMaze.cells[c.x][c.y][c.x].setSolution(true);
				return true;
			} else {
				return false;
			}
		}
	} else if (canTurnRight(c)) {
		currentMaze.cells[c.x][c.y][c.z].setExhausted(true);
		if (turnRight(c, solutionPath)) {
			currentMaze.cells[c.x][c.y][c.x].setSolution(true);
			return true;
		} else {
			currentMaze.cells[c.x][c.y][c.z].setExhausted(false);
			if (solveCurrentPath(c, solutionPath)) {
				currentMaze.cells[c.x][c.y][c.x].setSolution(true);
				return true;
			} else {
				return false;
			}
		}
	} else if (canTurnUp(c)) {
		currentMaze.cells[c.x][c.y][c.z].setExhausted(true);
		if (turnUp(c, solutionPath)) {
			currentMaze.cells[c.x][c.y][c.x].setSolution(true);
			return true;
		} else {
			currentMaze.cells[c.x][c.y][c.z].setExhausted(false);
			if (solveCurrentPath(c, solutionPath)) {
				currentMaze.cells[c.x][c.y][c.x].setSolution(true);
				return true;
			} else {
				return false;
			}
		}
	} else if (canTurnDown(c)) {
		currentMaze.cells[c.x][c.y][c.z].setExhausted(true);
		if (turnDown(c, solutionPath)) {
			currentMaze.cells[c.x][c.y][c.x].setSolution(true);
			return true;
		} else {
			currentMaze.cells[c.x][c.y][c.z].setExhausted(false);
			if (solveCurrentPath(c, solutionPath)) {
				currentMaze.cells[c.x][c.y][c.x].setSolution(true);
				return true;
			} else {
				return false;
			}
		}
	} else if (canTurnFront(c)) {
		currentMaze.cells[c.x][c.y][c.z].setExhausted(true);
		if (turnFront(c, solutionPath)) {
			currentMaze.cells[c.x][c.y][c.x].setSolution(true);
			return true;
		} else {
			currentMaze.cells[c.x][c.y][c.z].setExhausted(false);
			if (solveCurrentPath(c, solutionPath)) {
				currentMaze.cells[c.x][c.y][c.x].setSolution(true);
				return true;
			} else {
				return false;
			}
		}
	} else if (canTurnBack(c)) {
		currentMaze.cells[c.x][c.y][c.z].setExhausted(true);
		if (turnBack(c, solutionPath)) {
			currentMaze.cells[c.x][c.y][c.x].setSolution(true);
			return true;
		} else {
			currentMaze.cells[c.x][c.y][c.z].setExhausted(false);
			if (solveCurrentPath(c, solutionPath)) {
				currentMaze.cells[c.x][c.y][c.x].setSolution(true);
				return true;
			} else {
				return false;
			}
		}
	}
}

void Pathfinder::restartCurrentMaze() {
	for (int zLayer = 0; zLayer < currentMaze.zDepth; zLayer++) {
		for (int yLayer = 0; yLayer < currentMaze.yDepth; yLayer++) {
			for (int xLayer = 0; xLayer < currentMaze.xDepth; xLayer++) {
				currentMaze.cells[xLayer][yLayer][zLayer].setExhausted(false);
				currentMaze.cells[xLayer][yLayer][zLayer].setDeadEnd(false);
				currentMaze.cells[xLayer][yLayer][zLayer].setSolution(false);
			}
		}
	}
}

vector<string> Pathfinder::solveMaze() {
	Coordinate c;
	c.x = 0;
	c.y = 0;
	c.z = 0;
	vector<string> solutionPath;
	solutionPath.clear();
	if (solveCurrentPath(c, solutionPath)) {
		solutionPath.push_back("(0, 0, 0)");
		reverse(solutionPath.begin(), solutionPath.end());
	}
	restartCurrentMaze();
	return solutionPath;
}

Pathfinder::~Pathfinder() {
// TODO Auto-generated destructor stub
}

