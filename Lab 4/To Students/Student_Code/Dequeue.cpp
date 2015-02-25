/*
 * Dequeue.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#include "Dequeue.h"

namespace std {

Dequeue::Dequeue() {
	// TODO Auto-generated constructor stub

}

Dequeue::~Dequeue() {
	// TODO Auto-generated destructor stub
}

bool Dequeue::valueExists(int i){
	return cars.valueIsInList(i);
}

void Dequeue::push_front(int i) {
	if (cars.size() < MAX && !cars.valueIsInList(i)) {
		cars.insertHead(i);
	}
}
void Dequeue::push_back(int i) {
	if (cars.size() < MAX && !cars.valueIsInList(i)) {
		cars.insertTail(i);
	}
}
void Dequeue::pop_front() {
	if (!empty()) {
		cars.remove(cars.at(0));
	}
}
void Dequeue::pop_back() {
	if (!empty()) {
		cars.remove(cars.at(cars.size() - 1));
	}
}
bool Dequeue::empty() {
	return empty();
}
int Dequeue::front() {
	if (!empty()) {
		return cars.at(0);
	} else {
		return -1;
	}
}
int Dequeue::back() {
	if (!empty()) {
		return cars.at(cars.size() - 1);
	} else {
		return -1;
	}
}
bool Dequeue::full() {
	if (cars.size() >= MAX) {
		return true;
	} else {
		return false;
	}
}
int Dequeue::size() {
	return cars.size();
}

void Dequeue::pop(){
	pop_front();
}

int Dequeue::top(){
	return front();
}

void Dequeue::push(int i){
	push_front(i);
}

} /* namespace std */
