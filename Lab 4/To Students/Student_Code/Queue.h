/*
 * Queue.h
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "DataStructure.h"

namespace std {

class Queue: public DataStructure {
public:
	Queue();
	virtual ~Queue();

	void push(int i);
	void pop();
	bool empty();
	int top();
	bool full();
	int size();
	bool valueExists(int i);
private:
	LinkedList<int> cars;
	int MAX = 5;
};

} /* namespace std */

#endif /* QUEUE_H_ */
