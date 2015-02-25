/*
 * Stack.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#include "Stack.h"

namespace std {

Stack::Stack() {
	// TODO Auto-generated constructor stub

}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

bool Stack::valueExists(int i){
	return cars.valueIsInList(i);
}

bool Stack::empty() {
	if (cars.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool Stack::full() {
	if (cars.size() >= MAX) {
		return true;
	} else {
		return false;
	}
}

void Stack::push(int i) {
	if (cars.size() < MAX && !cars.valueIsInList(i)) {
		cars.insertHead(i);
	}
}

void Stack::pop() {
	if (!empty()) {
		cars.remove(cars.at(0));
	}
}

int Stack::top() {
	if (!empty()) {
		return cars.at(0);
	} else {
		return -1;
	}
}

int Stack::size() {
	return cars.size();
}

} /* namespace std */
