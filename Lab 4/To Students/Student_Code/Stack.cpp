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
	//cout << "stack.valueExists() called" << endl;
	return cars.valueIsInList(i);
}

bool Stack::empty() {
	//cout << "stack.empty() called" << endl;
	if (cars.size() == 0) {
		//cout << "stack.empty() returning true" << endl;
		return true;
	} else {
		//cout << "stack.empty() returning false" << endl;
		return false;
	}
}

bool Stack::full() {
	//cout << "stack.full() called" << endl;
	if (cars.size() >= MAX) {
		return true;
	} else {
		return false;
	}
}

void Stack::push(int i) {
	//cout << "stack.push() called" << endl;
	if (cars.size() < MAX && !cars.valueIsInList(i)) {
		cars.insertHead(i);
	}
}

void Stack::pop() {
	//cout << "stack.pop() called" << endl;
	if (!empty()) {
		cars.remove(cars.at(0));
	}
}

int Stack::top() {
	//cout << "stack.top() called" << endl;
	if (!empty()) {
		//cout << "stack.top() returning cars.at(0)" << endl;
		return cars.at(0);
	} else {
		//cout << "stack.top() returning -1" << endl;
		return -1;
	}
}

int Stack::size() {
	//cout << "stack.size() called" << endl;
	return cars.size();
}

} /* namespace std */
