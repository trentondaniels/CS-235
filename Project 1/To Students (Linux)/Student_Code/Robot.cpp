/*
 * Robot.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#include "Robot.h"

Robot::Robot() {
	// TODO Auto-generated constructor stub

}

Robot::Robot(string validatedInfo) :
		Fighter(validatedInfo) {
	maximumEnergy = magic * 2;
	energy = maximumEnergy;
}

int Robot::getDamage() {
	int totalDamage = strength + bonusDamage;
	cout << "Strength: " << strength << " BonusDamage: " << bonusDamage << endl;
	bonusDamage = 0;
	return totalDamage;
}

void Robot::reset() {
	Fighter::reset();
	energy = maximumEnergy;
	bonusDamage = 0;
}

void Robot::regenerate() {
	Fighter::regenerate();
}

bool Robot::useAbility() {
	bool abilityWasUsed;
	bonusDamage = calculateBonusDamage(abilityWasUsed);
	return abilityWasUsed;
}

int Robot::calculateBonusDamage(bool &abilityWasUsed) {

	double bonusDamage = 0;
	if (energy >= ROBOT_ABILITY_COST) {
		cout << "Calculating bonus damage...strength: " << strength
				<< " energy: " << energy << " maxEnergy: " << maximumEnergy
				<< endl;
		bonusDamage = (strength * (pow(((double)energy / (double)maximumEnergy), 4)));
		cout << "energy/maximumEnergy = " << (energy / maximumEnergy) <<
		" which raised to the fourth is " << (pow((energy / maximumEnergy),4)) << " times strength of " << strength << " is "
						<< bonusDamage << endl;
		cout << "bonus damage calculated at " << bonusDamage << endl;
		energy -= ROBOT_ABILITY_COST;
		abilityWasUsed = true;
	} else {
		abilityWasUsed = false;
	}
	cout << " returning: " << (int) bonusDamage << endl;
	return (int) bonusDamage;

}

Robot::~Robot() {
	// TODO Auto-generated destructor stub
}

