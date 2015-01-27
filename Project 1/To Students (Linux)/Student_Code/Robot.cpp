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

Robot::Robot(string validatedInfo) {
	maximumEnergy = magic*2;
	energy = maximumEnergy;
}

int Robot::getDamage() {
	int totalDamage = strength + bonusDamage;
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

int Robot::calculateBonusDamage(bool &abilityWasUsed){

	double bonusDamage;
	if(energy >= ROBOT_ABILITY_COST){
		bonusDamage= (strength  * ((energy/maximumEnergy)^4));
		energy -= ROBOT_ABILITY_COST;
		abilityWasUsed=true;
	}else{
		bonusDamage = 0;
		abilityWasUsed=false;
	}
	return (int)bonusDamage;

}

Robot::~Robot() {
	// TODO Auto-generated destructor stub
}

