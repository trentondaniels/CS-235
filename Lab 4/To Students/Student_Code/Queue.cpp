/*
 * Queue.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#include "Queue.h"

namespace std {

Queue::Queue() {
	// TODO Auto-generated constructor stub

}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

bool Queue::valueExists(int i){
	return cars.valueIsInList(i);
}

bool Queue::empty() {
	if (cars.size() == 0) {
		return true;
	} else {
		return false;
	}
}

bool Queue::full() {
	if (cars.size() >= MAX) {
		return true;
	} else {
		return false;
	}
}

void Queue::push(int i) {
	if (cars.size() < MAX && !cars.valueIsInList(i)) {
		cars.insertHead(i);
	}
}

void Queue::pop() {
	if (!empty()) {
		cars.remove(cars.at(cars.size() - 1));
	}
}

int Queue::top() {
	if (!empty()) {
		return cars.at(cars.size() - 1);
	} else {
		return -1;
	}
}

int Queue::size() {
	return cars.size();
}

} /* namespace std */
