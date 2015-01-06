/*
 * Cleric.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef CLERIC_H_
#define CLERIC_H_

#include "Fighter.h"

class Cleric: public Fighter {
public:
	Cleric();
	Cleric(string info);
	virtual ~Cleric();

	void reset();
	void regenerate();
	bool useAbility();
};

#endif /* CLERIC_H_ */
