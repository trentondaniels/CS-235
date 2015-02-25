/*
 * Station.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#include "Station.h"

namespace std {

Station::Station() {

}

Station::~Station() {
	// TODO Auto-generated destructor stub
}

bool Station::carExists(int car) {
	if(stack.valueExists(car) || queue.valueExists(car) || dequeue.valueExists(car)){
		return true;
	}else{
		return false;
	}
}

bool Station::addToStation(int car) {
	if (!carExists(car) && currentCar == -1 && car >= 0) {
		currentCar = car;
		return true;
	} else {
		return false;
	}
}

int Station::showCurrentCar() {
	if (currentCar != -1) {
		return currentCar;
	} else {
		return -1;
	}
}

bool Station::removeFromStation() {
	if (currentCar != -1) {
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}

bool Station::addToStack() {
	if (currentCar != -1) {
		stack.push(currentCar);
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}

bool Station::removeFromStack() {
	if (currentCar != -1 && !stack.empty()) {
		currentCar = stack.top();
		stack.pop();
		return true;
	} else {
		return false;
	}
}

int Station::showTopOfStack() {
	return stack.top();
}

int Station::showSizeOfStack() {
	return stack.size();
}

bool Station::addToQueue() {
	if (currentCar != -1) {
		queue.push(currentCar);
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}

bool Station::removeFromQueue() {
	if (currentCar != -1 && !queue.empty()) {
		currentCar = queue.top();
		queue.pop();
		return true;
	} else {
		return false;
	}
}

int Station::showTopOfQueue() {
	return queue.top();
}

int Station::showSizeOfQueue() {
	return queue.size();
}

bool Station::addToDequeLeft(){
	if (currentCar != -1) {
			dequeue.push_front(currentCar);
			currentCar = -1;
			return true;
		} else {
			return false;
		}
}
bool Station::addToDequeRight(){
	if (currentCar != -1) {
			dequeue.push_back(currentCar);
			currentCar = -1;
			return true;
		} else {
			return false;
		}
}
bool Station::removeFromDequeLeft(){
	if (currentCar != -1 && !dequeue.empty()) {
			currentCar = dequeue.front();
			dequeue.pop_front();
			return true;
		} else {
			return false;
		}
}
bool Station::removeFromDequeRight(){
	if (currentCar != -1 && !dequeue.empty()) {
			currentCar = dequeue.back();
			dequeue.pop_back();
			return true;
		} else {
			return false;
		}
}
int Station::showTopOfDequeLeft(){
	return dequeue.front();
}
int Station::showTopOfDequeRight(){
	return dequeue.back();
}
int Station::showSizeOfDeque(){
	return dequeue.size();
}

} /* namespace std */
