/*
 * LinkedList.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: Jason
 */

#include "LinkedList.h"
using namespace std;

template<class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	current = NULL;
	temporary = NULL;
	temporary2 = NULL;

}

template<class T>
int LinkedList<T>::size() {
	int size = 0;
	if (head != NULL) {
		size = 1;
		node* sizeChecker = head;
		while (sizeChecker->next != NULL) {
			sizeChecker = sizeChecker->next;
			size += 1;
		}
	}
	return size;
}

template<class T>
void LinkedList<T>::insertHead(T value) {
	head = new node();
	head->value = value;
	head->next = NULL;
	head->previous = NULL;

	temporary = head;
	current = head;

}

template<class T>
void LinkedList<T>::insertTail(T value) {
	current = head;
	while (current->next != NULL) {
		temporary = current;
		current = current->next;
	}
	current = new node();
	current->value = value;
	current->next = NULL;
	current->previous = temporary;
	temporary->next = current;

}

template<class T>
void LinkedList<T>::insertAfter(T value, T insertionNode) {
	if (this->size() > 0) {
		current = head;
		do {
			if (current->value == insertionNode) {
				temporary = current;
				temporary2 = current->next;

				current = new node();
				current->value = value;
				current->next = temporary2;
				current->previous = temporary;
				temporary->next = current;
			} else {
				current = current->next;
			}
		} while (current->next != NULL);
	}
}

template<class T>
void LinkedList<T>::remove(T value) {
	if (this->size() > 0) {
		current = head;
		do {
			if (current->value == value) {
				temporary = current->previous;
				temporary2 = current->next;

				delete current;

				temporary->next = temporary2;
				temporary2->previous = temporary;
			} else {
				current = current->next;
			}
		} while (current->next != NULL);
	}
}

template<class T>
void LinkedList<T>::clear(){
	if(this->size() > 0){
		current = head;
		do{
			temporary = current;
			current = current->next;

			delete temporary;
		}while(current->next != NULL);
	}
}

template<class T>
T LinkedList<T>::at(int index){
	if(this->size() >= index){
		current = head;
		for(int i = 0; i < index; i++){
			current = current->next;
		}
		T value = current ->value;
		return value;
	}
}


template<class T>
LinkedList<T>::~LinkedList() {
	// TODO Auto-generated destructor stub
}

