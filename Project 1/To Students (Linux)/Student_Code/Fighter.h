/*
 * Fighter.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef FIGHTER_H_
#define FIGHTER_H_

#include "FighterInterface.h"
#include <cmath>

class Fighter: public FighterInterface {
public:
	Fighter();
	Fighter(string validatedInfo);
	virtual ~Fighter();

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	void takeDamage(int damage);
	virtual void regenerate();
	virtual void reset();
	virtual int getDamage() = 0;
	virtual bool useAbility() = 0;
protected:
	string name;
	int maximumHP, currentHP, strength, speed, magic;
};

#endif /* FIGHTER_H_ */
