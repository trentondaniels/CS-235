/*
 * CircularDLL.h
 *
 *  Created on: Mar 4, 2015
 *      Author: Jason
 */

#ifndef STUDENT_CODE_CIRCULARDLL_H_
#define STUDENT_CODE_CIRCULARDLL_H_

#include "CircularDLLInterface.h"

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
	struct node{
		public:
			string name;
			node* next;
			node* previous;
		};


		node* head;
		node* temporary;
		node* temporary2;
		node* current;
		node* tail;
	};
};

} /* namespace std */

#endif /* STUDENT_CODE_CIRCULARDLL_H_ */
