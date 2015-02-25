/*
 * LinkedList.h
 *
 *  Created on: Jan 27, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_LINKEDLIST_H_
#define TO_STUDENTS_STUDENT_CODE_LINKEDLIST_H_

#include <stdexcept>
#include <iostream>
using namespace std;


template <class T>

class LinkedList{

public:
	LinkedList();
	virtual ~LinkedList();

	void insertHead(T value);
	void insertTail(T value);
	void insertAfter(T value, T insertionNode);
	void remove(T value);
	void clear();
	T at(int index);
	int size();

	bool valueIsInList(T value);
private:

	struct node{
	public:
		T value;
		node* next;
		node* previous;
	};


	node* head;
	node* temporary;
	node* temporary2;
	node* current;
};




#endif /* TO_STUDENTS_STUDENT_CODE_LINKEDLIST_H_ */
