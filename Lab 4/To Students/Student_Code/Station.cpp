/*
 * Station.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#include "Station.h"

namespace std {

Station::Station() {
	//cout << "Station created" << endl;
}

Station::~Station() {
	//cout << "Station destroyed" << endl;
}

bool Station::carExists(int car) {
	//cout << "station.carExists() called" << endl;
	if(stack.valueExists(car) || queue.valueExists(car) || dequeue.valueExists(car)){
		return true;
	}else{
		return false;
	}
}

bool Station::addToStation(int car) {
	//cout << "station.adddToStation() called" << endl;
	if (!carExists(car) && currentCar == -1 && car >= 0) {
		currentCar = car;
		return true;
	} else {
		return false;
	}
}

int Station::showCurrentCar() {
	//cout << "station.showCurrentCar() called" << endl;
	return currentCar;
}

bool Station::removeFromStation() {
	//cout << "station.removeFromStation() called" << endl;
	if (currentCar != -1) {
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}

bool Station::addToStack() {
	//cout << "station.addToStack() called" << endl;
	if (currentCar != -1) {
		stack.push(currentCar);
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}

bool Station::removeFromStack() {
	//cout << "station.removeFromStack() called" << endl;
	if (currentCar == -1 && !stack.empty()) {
		currentCar = stack.top();
		stack.pop();
		return true;
	} else {
		return false;
	}
}

int Station::showTopOfStack() {
	//cout << "station.showTopOfStack() called" << endl;
	//cout << "station.showTopOfStack() returning " << stack.top() << endl;
	return stack.top();
}

int Station::showSizeOfStack() {
	//cout << "station.showSizeOfStack() called" << endl;
	return stack.size();
}

bool Station::addToQueue() {
	//cout << "station.addToQueue() called" << endl;
	if (currentCar != -1) {
		queue.push(currentCar);
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}

bool Station::removeFromQueue() {
	//cout << "station.removeFromQueue() called" << endl;
	if (currentCar == -1 && !queue.empty()) {
		currentCar = queue.top();
		queue.pop();
		return true;
	} else {
		return false;
	}
}

int Station::showTopOfQueue() {
	//cout << "station.showTopOfQueue() called" << endl;
	return queue.top();
}

int Station::showSizeOfQueue() {
	//cout << "station.showSizeOfQueue() called" << endl;
	return queue.size();
}

bool Station::addToDequeLeft(){
	//cout << "station.addToDequeLeft() called" << endl;
	if (currentCar != -1) {
			dequeue.push_front(currentCar);
			currentCar = -1;
			return true;
		} else {
			return false;
		}
}
bool Station::addToDequeRight(){
	//cout << "station.addToDequeRight() called" << endl;
	if (currentCar != -1) {
			dequeue.push_back(currentCar);
			currentCar = -1;
			return true;
		} else {
			return false;
		}
}
bool Station::removeFromDequeLeft(){
	//cout << "station.removeFromDequeLeft() called" << endl;
	if (currentCar == -1 && !dequeue.empty()) {
			currentCar = dequeue.front();
			dequeue.pop_front();
			return true;
		} else {
			return false;
		}
}
bool Station::removeFromDequeRight(){
	//cout << "station.removeFromDequeRight() called" << endl;
	if (currentCar == -1 && !dequeue.empty()) {
			currentCar = dequeue.back();
			dequeue.pop_back();
			return true;
		} else {
			return false;
		}
}
int Station::showTopOfDequeLeft(){
	//cout << "station.showTopOfDequeLeft() called" << endl;
	return dequeue.front();
}
int Station::showTopOfDequeRight(){
	//cout << "station.showTopOfDequeRight() called" << endl;
	return dequeue.back();
}
int Station::showSizeOfDeque(){
	//cout << "station.showSizeOfDeque() called" << endl;
	return dequeue.size();
}

} /* namespace std */
