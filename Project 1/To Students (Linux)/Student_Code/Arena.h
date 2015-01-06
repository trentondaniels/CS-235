/*
 * Arena.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef ARENA_H_
#define ARENA_H_

#include "ArenaInterface.h"
#include "Fighter.h"
#include <vector>

class Arena: public ArenaInterface {
public:
	Arena();
	virtual ~Arena();

	bool addFighter(string info);

	bool stringMakesValidFighter(string info);

	bool removeFighter(string name);

	FighterInterface* getFighter(string name);

	int getSize();

private:
	vector<Fighter*> fighters;
};

#endif /* ARENA_H_ */
