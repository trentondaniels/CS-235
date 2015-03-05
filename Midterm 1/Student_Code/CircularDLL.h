/*
 * CircularDLL.h
 *
 *  Created on: Mar 4, 2015
 *      Author: Jason
 */

#ifndef STUDENT_CODE_CIRCULARDLL_H_
#define STUDENT_CODE_CIRCULARDLL_H_

#include "CircularDLLInterface.h"
#include<iostream>

namespace std {

class CircularDLL: public CircularDLLInterface {
public:
	CircularDLL();
	virtual ~CircularDLL();

	bool insertHead(string name);
	bool insertTail(string name);
	bool insertAt(string name, int index);
	bool removeHead();
	bool removeTail();
	bool removeAt(int index);
	void clear();
	int size();
	string atFromHead(int index);
	string atFromTail(int index);

	bool valueIsInList(string name);

private:
	int sizeOfList;
	struct node {
	public:
		string name;
		node* next;
		node* previous;
	};

	node* head;
	node* temporary;
	node* current;
	node* tail;
};

}
;

#endif /* STUDENT_CODE_CIRCULARDLL_H_ */
