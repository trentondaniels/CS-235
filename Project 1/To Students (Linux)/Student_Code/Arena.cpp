/*
 * Arena.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#include "Arena.h"
#include<sstream>

Arena::Arena() {
	// TODO Auto-generated constructor stub

}

bool Arena::addFighter(string info) {
	if (stringMakesValidFighter(info)) {
		switch (getFighterTypeFromString(info)) {
		case 'R':
			fighters.push_back(new Robot(info));
			break;
		case 'C':
			fighters.push_back(new Cleric(info));
			break;
		case 'A':
			fighters.push_back(new Archer(info));
			break;
		default:
			return false;
			break;
		}
		return true;
	} else {
		return false;
	}
}

char Arena::getFighterTypeFromString(string info) {
	string name;
	char type;

	stringstream ss;
	ss << info;

	ss >> name;
	ss >> type;
	return type;
}

bool Arena::stringMakesValidFighter(string info) {

	string name;
	char type;
	int maxHP, strength, speed, magic;

	stringstream ss;
	ss << info;

	ss >> name;
	if (getFighter(name) != NULL) { //If fighter is already in vector
		cout >> "Fighter already exists" << endl;
		return false;
	}
	ss >> type;
	if (type != 'R' && type != 'C' && type != 'A') {
		cout >> "Invalid Type Indicator" << endl;
		return false;
	}
	ss >> maxHP >> strength >> speed >> magic;
	if (maxHP <= 0 || strength <= 0 || speed <= 0 || magic <= 0) {
		cout >> "Invalid attribute value" << endl;
		return false;
	}

	if (ss.fail()) {
		cout >> "Invalid information format" << endl;
		return false;
	} else {
		return true;
	}
}

bool Arena::removeFighter(string name) {
	for (int i = 0; i < fighters.size(); i++) {
		if (fighters.at(i)->getName() == name) {
			fighters.erase(fighters.begin() + i);
			return true;
		}
	}
	return false;
}

FighterInterface* Arena::getFighter(string name) {
	for (int i = 0; i < fighters.size(); i++) {
		if (fighters.at(i)->getName() == name) {
			return fighters.at(i);
		}
	}
	return NULL;
}

int Arena::getSize() {
	return fighters.size();
}

Arena::~Arena() {
	// TODO Auto-generated destructor stub
}

