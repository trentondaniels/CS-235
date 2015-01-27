/*
 * Arena.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef ARENA_H_
#define ARENA_H_

#include "ArenaInterface.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Arena: public ArenaInterface {
public:
	Arena();
	virtual ~Arena();

	bool addFighter(string info);

	char getFighterTypeFromString(string info);

	bool stringMakesValidFighter(string info);

	bool removeFighter(string name);

	FighterInterface* getFighter(string name);

	int getSize();

private:
	vector<Fighter*> fighters;
};

#endif /* ARENA_H_ */
