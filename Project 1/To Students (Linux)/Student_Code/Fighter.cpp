/*
 * Fighter.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#include "Fighter.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Fighter::Fighter() {
	// TODO Auto-generated constructor stub
	cout << "Default Fighter Constructor" << endl;
}

Fighter::Fighter(string validatedInfo) {
	char typeIndicator;
	stringstream ss;
	ss << validatedInfo;

	ss >> name;
	ss >> typeIndicator;
	ss >> maximumHP >> strength >> speed >> magic;
}

string Fighter::getName() {
	return name;
}

int Fighter::getMaximumHP() {
	return maximumHP;
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

void Fighter::takeDamage(int damage) {
	double damageTaken = damage - (speed / 4);
	if (damageTaken == 0) {
		currentHP -= 1;
	} else {
		currentHP -= damageTaken;
	}

}

void Fighter::reset() {
	currentHP = maximumHP;
}

void Fighter::regenerate(){
	if(strength/6 < 1){
		currentHP += 1;
	}else{
		currentHP += strength/6;
	}
	if(currentHP > maximumHP){
		currentHP = maximumHP;
	}
}
Fighter::~Fighter() {
	// TODO Auto-generated destructor stub
}

