/*
 * Archer.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#include "Archer.h"

Archer::Archer() {
	// TODO Auto-generated constructor stub

}

Archer::Archer(string validatedInfo){
	initialSpeed = speed;
}

Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

int Archer::getDamage() {
	return speed;
}
void Archer::reset() {
	Fighter::reset();
	speed = initialSpeed;
}
void Archer::regenerate() {
	Fighter::regenerate();
}
bool Archer::useAbility() {
	speed += 1;
	return true;
}
