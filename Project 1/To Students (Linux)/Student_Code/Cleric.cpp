/*
 * Cleric.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#include "Cleric.h"


Cleric::Cleric() {
	// TODO Auto-generated constructor stub
	cout << "Cleric cannot be created without information" << endl;

}

Cleric::Cleric(string validatedInfo):Fighter(validatedInfo){
	cout << "Calling Cleric(string info)" << endl;
	maximumMana = magic*5;
	mana = maximumMana;
}

Cleric::~Cleric() {
	// TODO Auto-generated destructor stub
}

int Cleric::getDamage() {
	return magic;
}
void Cleric::reset() {
	Fighter::reset();
	mana = maximumMana;
}
void Cleric::regenerate() {
	Fighter::regenerate();
	if(magic/5 < 1){
		mana += 1;
	}else{
		mana += magic/5;
	}
	if (mana > maximumMana){
		mana = maximumMana;
	}
}
bool Cleric::useAbility() {
	if(mana >= CLERIC_ABILITY_COST){
		if(magic/3 < 1){
			currentHP += 1;
		}else{
			currentHP += magic/3;
		}
		if(currentHP > maximumHP){
			currentHP = maximumHP;
		}
		mana -= CLERIC_ABILITY_COST;
		return true;
	}else{
		return false;
	}
}
