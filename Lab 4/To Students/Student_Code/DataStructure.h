/*
 * DataStructure.h
 *
 *  Created on: Feb 24, 2015
 *      Author: JasonT
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#include"LinkedList.h"
namespace std {

class DataStructure {
public:
	DataStructure();
	virtual ~DataStructure();

	virtual void push(int i) = 0;
	virtual void pop() = 0;
	virtual bool empty() = 0;
	virtual int top() = 0;
	virtual bool full() = 0;
	virtual int size() = 0;
	virtual bool valueExists(int i) = 0;
private:
	LinkedList<int> cars;
	int MAX = 5;
};

} /* namespace std */

#endif /* DATASTRUCTURE_H_ */
