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
	if (stack.valueExists(car) || queue.valueExists(car)
			|| deque.valueExists(car) || iRDeque.valueExists(car) || oRDeque.valueExists(car)) {
		return true;
	} else {
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

bool Station::addToDequeLeft() {
	//cout << "station.addToDequeLeft() called" << endl;
	if (currentCar != -1) {
		deque.push_front(currentCar);
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}
bool Station::addToDequeRight() {
	//cout << "station.addToDequeRight() called" << endl;
	if (currentCar != -1) {
		deque.push_back(currentCar);
		currentCar = -1;
		return true;
	} else {
		return false;
	}
}
bool Station::removeFromDequeLeft() {
	//cout << "station.removeFromDequeLeft() called" << endl;
	if (currentCar == -1 && !deque.empty()) {
		currentCar = deque.front();
		deque.pop_front();
		return true;
	} else {
		return false;
	}
}
bool Station::removeFromDequeRight() {
	//cout << "station.removeFromDequeRight() called" << endl;
	if (currentCar == -1 && !deque.empty()) {
		currentCar = deque.back();
		deque.pop_back();
		return true;
	} else {
		return false;
	}
}
int Station::showTopOfDequeLeft() {
	//cout << "station.showTopOfDequeLeft() called" << endl;
	return deque.front();
}
int Station::showTopOfDequeRight() {
	//cout << "station.showTopOfDequeRight() called" << endl;
	return deque.back();
}
int Station::showSizeOfDeque() {
	//cout << "station.showSizeOfDeque() called" << endl;
	return deque.size();
}

bool Station::addToIRDequeLeft() {
	if(!iRDeque.full() && currentCar != -1){
		iRDeque.push_front(currentCar);
		currentCar = -1;
		return true;
	}else{
		return false;
	}

}
bool Station::removeFromIRDequeLeft() {
	if(currentCar == -1 && !iRDeque.empty()){
		currentCar = iRDeque.front();
		iRDeque.pop_front();
		return true;
	}else{
		return false;
	}
}
bool Station::removeFromIRDequeRight() {
	if(currentCar == -1 && !iRDeque.empty()){
			currentCar = iRDeque.back();
			iRDeque.pop_back();
			return true;
		}else{
			return false;
		}
}
int Station::showTopOfIRDequeLeft() {
	return iRDeque.front();
}
int Station::showTopOfIRDequeRight() {
	return iRDeque.back();
}
int Station::showSizeOfIRDeque() {
	return iRDeque.size();
}

bool Station::addToORDequeLeft() {
	if(!oRDeque.full() && currentCar != -1){
			oRDeque.push_front(currentCar);
			currentCar = -1;
			return true;
		}else{
			return false;
		}
}
bool Station::addToORDequeRight() {
	if(!oRDeque.full() && currentCar != -1){
				oRDeque.push_back(currentCar);
				currentCar = -1;
				return true;
			}else{
				return false;
			}
}
bool Station::removeFromORDequeLeft() {
	if(currentCar == -1 && !oRDeque.empty()){
			currentCar = oRDeque.front();
			oRDeque.pop_front();
			return true;
		}else{
			return false;
		}
}
int Station::showTopOfORDequeLeft() {
	return oRDeque.front();
}
int Station::showSizeOfORDeque() {
	return oRDeque.size();
}

} /* namespace std */
