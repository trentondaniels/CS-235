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
	Cleric(string validatedInfo);
	virtual ~Cleric();

	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
private:
	int mana, maximumMana;
};

#endif /* CLERIC_H_ */
