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
bool LinkedList<T>::valueIsInList(T value) {
	if (this->size() > 0) {
		if (head->value == value) {
			return true;
		}
		current = head;
		while (current->next != NULL) {
			current = current->next;
			if (current->value == value) {
				return true;
			}
		}
	}
	return false;
}

template<class T>
void LinkedList<T>::insertHead(T value) {
	if (!this->valueIsInList(value)) {
		if (this->size() > 0) {

			current = head;
			head = new node();

			head->next = current;
			head->previous = NULL;
			current->previous = head;

			head->value = value;
		} else {
			head = new node();
			head->value = value;
			head->next = NULL;
			head->previous = NULL;

			temporary = head;
			current = head;
		}
	}

}

template<class T>
void LinkedList<T>::insertTail(T value) {
	if (!this->valueIsInList(value)) {
		if (this->size() == 0) {
			this->insertHead(value);
			return;
		}
		current = head;
		temporary = current;
		while (current->next != NULL) {
			current = current->next;
			temporary = current;
		}
		current = new node();
		current->value = value;
		current->next = NULL;
		current->previous = temporary;
		temporary->next = current;
	}
}

template<class T>
void LinkedList<T>::insertAfter(T value, T insertionNode) {
	if (!this->valueIsInList(value)) {
		if (this->size() > 0) {
			if (head->value == insertionNode) {
				current = head;
				temporary = head->next;
				current = new node();
				current->value = value;
				current->next = temporary;
				current->previous = head;
				head->next = current;
			}
			current = head;
			do {
				if (current->next != NULL) {
					current = current->next;
				}
				if (current->value == insertionNode) {
					temporary = current;
					temporary2 = current->next;

					current = new node();
					current->value = value;
					current->next = temporary2;
					current->previous = temporary;
					temporary->next = current;
				}
			} while (current->next != NULL);
		}
	}
}

template<class T>
void LinkedList<T>::remove(T value) {
	if (this->size() > 0) {
		if (head->value == value) {
			temporary = head->next;
			delete head;
			head = temporary;
			return;
		}
		current = head;
		while (current->next != NULL) {
			current = current->next;
			if (current->value == value) {
				temporary = current->previous;
				temporary2 = current->next;

				delete current;

				if (temporary != NULL) {
					temporary->next = temporary2;
				}
				if (temporary2 != NULL) {
					temporary2->previous = temporary;
				}
				return;
			}
		}
	}
}

template<class T>
void LinkedList<T>::clear() {
	if (this->size() > 0) {
		if (this->size() == 1) {
			delete head;
			head = NULL;
			current = NULL;
			temporary = NULL;
			temporary2 = NULL;
			return;
		} else {
			current = head;
			while (current->next != NULL) {
				temporary = current;
				current = current->next;

				delete temporary;

			}
			delete current;

		}

	}
	head = NULL;
	current = NULL;
	temporary = NULL;
	temporary2 = NULL;
}

template<class T>
T LinkedList<T>::at(int index) {
	if (index >= 0 && index < this->size()) {
		current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		T value = current->value;
		return value;
	} else {
		throw out_of_range("index out of bounds");
	}

}

template<class T>
LinkedList<T>::~LinkedList() {
	this->clear();
}

