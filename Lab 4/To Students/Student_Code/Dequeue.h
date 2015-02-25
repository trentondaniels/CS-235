/*
 * Dequeue.h
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#include "DataStructure.h"

namespace std {

class Dequeue: public DataStructure {
public:
	Dequeue();
	virtual ~Dequeue();

	void push_front(int i);
	void push_back(int i);
	void pop_front();
	void pop_back();
	bool empty();
	int front();
	int back();
	bool full();
	int size();
	bool valueExists(int i);

	void pop();
	int top();
	void push(int i);
private:
	LinkedList<int> cars;
	int MAX = 5;
};

} /* namespace std */

#endif /* DEQUEUE_H_ */
