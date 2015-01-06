/*
 * Fighter.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef FIGHTER_H_
#define FIGHTER_H_

#include "FighterInterface.h"

class Fighter: public FighterInterface {
public:
	Fighter();
	Fighter(string info);
	virtual ~Fighter();

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	int getDamage();
	void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();
protected:
	string name;
	int maxinumHP, currentHP, strength, speed, magic, damage;
};

#endif /* FIGHTER_H_ */
