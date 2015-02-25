/*
 * Station.h
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#ifndef STATION_H_
#define STATION_H_

#include "StationInterface.h"
#include "Stack.h"
#include "Queue.h"
#include "Dequeue.h"

namespace std {

class Station: public StationInterface {
public:
	Station();
	virtual ~Station();

	bool carExists(int car);

	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();
	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();

	bool addToQueue();
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();

	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();

private:
	Stack stack;
	Queue queue;
	Dequeue dequeue;
	int currentCar = -1;
};

} /* namespace std */

#endif /* STATION_H_ */
