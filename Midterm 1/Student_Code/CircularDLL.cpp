/*
 * CircularDLL.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: Jason
 */

#include "CircularDLL.h"

namespace std {

CircularDLL::CircularDLL() {
	head = NULL;
	current = NULL;
	temporary = NULL;
	temporary2 = NULL;
	tail = NULL;
}

CircularDLL::~CircularDLL() {
	// TODO Auto-generated destructor stub
}

bool CircularDLL::valueIsInList(string name) {
	if (this->size() > 0) {
		if (head->name == name) {
			return true;
		}
		current = head;
		while (current->next != head) {
			current = current->next;
			if (current->name == name) {
				return true;
			}
		}
	}
	return false;
}

bool CircularDLL::insertHead(string name) {
	if (!this->valueIsInList(name)) {
		if (this->size() > 0) {

			current = head;
			head = new node();

			head->next = current;
			head->previous = tail;
			tail->next = head;
			current->previous = head;

			head->name = name;
		} else {
			head = new node();
			head->name = name;
			head->next = head;
			head->previous = head;
			tail->next = head;
			tail->previous = head;

			temporary = head;
			current = head;
		}
		return true;
	} else {
		return false;
	}

}
bool CircularDLL::insertTail(string name) {
	if (!this->valueIsInList(name)) {
		if (this->size() == 0) {
			this->insertHead(name);
			return true;
		}
		current = head;
		temporary = current;
		while (current->next != head) {
			current = current->next;
			temporary = current;
		}
		current = new node();
		current->name = name;
		current->next = head;
		current->previous = temporary;
		temporary->next = current;
		head->previous = current;
		tail = current;
		return true;
	} else {
		return false;
	}
}
bool CircularDLL::insertAt(string name, int index) {
	if (!this->valueIsInList(name)) {
		if (this->size() > index && index >= 0) {
			current = head;
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
			temporary = current;
			temporary2 = current->next;
			current = new node();
			current->previous = temporary;
			current->next = temporary2;
			current->name = name;
			temporary->next = current;
			temporary2->previous = current;

			return true;
		}
	} else {
		return false;
	}
}
bool CircularDLL::removeHead() {
	if (this->size() > 0) {
		if (this->size() == 1) {
			delete head;
			head = NULL;
			current = NULL;
			temporary = NULL;
			temporary2 = NULL;
			tail = NULL;
			return true;
		} else {
			temporary = head->next;
			delete head;
			head = temporary;
			tail->next = head;
			head->previous = tail;
			return true;
		}
		return false;
	}
}
bool CircularDLL::removeTail() {
	if (this->size() > 0) {
		if (this->size() == 1) {
			delete tail;
			head = NULL;
			current = NULL;
			temporary = NULL;
			temporary2 = NULL;
			tail = NULL;
			return true;
		} else {
			temporary = tail->previous;
			delete tail;
			tail = temporary;
			tail->next = head;
			head->previous = tail;
			return true;
		}
		return false;
	}
}
}
bool CircularDLL::removeAt(int index) {
	if (this->size() > index && index >= 0) {
		current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		temporary = current->next;
		temporary2 = current->previous;
		delete current;
		temporary->previous = temporary2;
		temporary2->next = temporary;
	}
}
void CircularDLL::clear() {
	if (this->size() > 0) {
		if (this->size() == 1) {
			delete head;
			head = NULL;
			current = NULL;
			temporary = NULL;
			temporary2 = NULL;
			tail = NULL;
			return;
		} else {
			current = head;
			while (current->next != tail) {
				temporary = current;
				current = current->next;

				delete temporary;

			}
			delete current;
			delete tail;

		}

	}
	head = NULL;
	current = NULL;
	temporary = NULL;
	temporary2 = NULL;
}
int CircularDLL::size() {
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
string CircularDLL::atFromHead(int index) {
	if (this->size() > index && index >= 0) {
		current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->name;
	} else {
		return "invalid";
	}
}
string CircularDLL::atFromTail(int index) {
	if (this->size() > index && index >= 0) {
		current = tail;
		for (int i = 0; i < index; i++) {
			current = current->previous;
		}
		return current->name;
	} else {
		return "invalid";
	}

} /* namespace std */
