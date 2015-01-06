/*
 * Archer.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef ARCHER_H_
#define ARCHER_H_

#include "Fighter.h"

class Archer: public Fighter {
public:
	Archer();
	Archer(string info);
	virtual ~Archer();

	void reset();
	void regenerate();
	bool useAbility();
};

#endif /* ARCHER_H_ */
