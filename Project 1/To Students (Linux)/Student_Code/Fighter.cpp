/*
 * Fighter.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#include "Fighter.h"
#include <sstream>

Fighter::Fighter() {
	// TODO Auto-generated constructor stub

}

Fighter::Fighter(string info){
	char typeIndicator;
	stringstream ss;
	ss << info;

	ss >> name;
	ss >> typeIndicator;
	ss >> maxinumHP >> strength >> speed >> magic;
}

string Fighter::getName() {
	return name;
}

int Fighter::getMaximumHP() {
	return maxinumHP;
}
int Fighter::getCurrentHP() {
	return currentHP;
}
int Fighter::getStrength() {
	return strength;
}
int Fighter::getSpeed() {
	return speed;
}
int Fighter::getMagic() {
	return magic;
}
int Fighter::getDamage() {
	return damage;
}
void Fighter::takeDamage(int damage) {

}

Fighter::~Fighter() {
	// TODO Auto-generated destructor stub
}

