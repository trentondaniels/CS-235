/*
 * Stack.h
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#ifndef STACK_H_
#define STACK_H_

#include "DataStructure.h"

namespace std {

class Stack: public DataStructure {
public:
	Stack();
	virtual ~Stack();

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

#endif /* STACK_H_ */
