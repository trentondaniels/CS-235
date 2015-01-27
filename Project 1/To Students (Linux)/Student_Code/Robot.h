/*
 * Robot.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Fighter.h"


class Robot: public Fighter {
public:
	Robot();
	Robot(string validatedInfo);
	virtual ~Robot();

	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
private:
	int bonusDamage = 0, energy, maximumEnergy;
	int calculateBonusDamage(bool &abilityWasUsed);
};

#endif /* ROBOT_H_ */
