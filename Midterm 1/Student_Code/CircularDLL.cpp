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
	tail = NULL;
	sizeOfList = 0;
}

CircularDLL::~CircularDLL() {
	clear();
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
	cout << "Insert head called" << endl;
	if (!this->valueIsInList(name)) {
		if (this->size() > 0) {
			cout << "Size > 0...";

			current = new node();
			sizeOfList++;
			current->next = head;
			current->previous = tail;
			current->next->previous = current;
			current->previous->next = current;
			current->name = name;
			head = current;
		} else {
			cout << "Current size 0...";

			head = new node();
			sizeOfList++;
			head->name = name;
			head->next = head;
			head->previous = head;
			tail = head;

		}
		cout << "Head added name:" << head->name << endl;
		return true;
	} else {
		cout << "Name already in list" << endl;
		return false;
	}

}
bool CircularDLL::insertTail(string name) {
	cout << "Insert tail called...";
	if (!this->valueIsInList(name)) {
		if (this->size() == 0) {
			cout << "Current size 0...";
			head = new node();
			sizeOfList++;
			head->name = name;
			head->next = head;
			head->previous = head;
			tail = head;
			cout << "Tail added name:" << tail->name << endl;
			return true;
		}
		cout << "Size > 0...";
		current = new node();
		sizeOfList++;
		current->previous = tail;
		current->next = head;
		current->previous->next = current;
		current->next->previous = current;
		current->name = name;
		tail = current;
		cout << "Tail added name:" << tail->name << endl;
		return true;
	} else {
		cout << "Name already in list" << endl;
		return false;
	}
}
bool CircularDLL::insertAt(string name, int index) {
	if (!this->valueIsInList(name)) {
		if (index >= 0) {
			current = head;
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
			temporary = new node();
			sizeOfList++;
			temporary->next = current;
			temporary->previous = current->previous;
			temporary->previous->next = temporary;
			temporary->next->previous = temporary;
			temporary->name = name;
			cout << name << " added at " << index << endl;
			return true;
		}
	} else {
		cout << "Name already in list" << endl;
		return false;
	}
}
bool CircularDLL::removeHead() {
	if (this->size() > 0) {
		if (this->size() == 1) {
			delete head;
			sizeOfList--;
			head = NULL;
			current = NULL;
			temporary = NULL;
			tail = NULL;
			return true;
		} else {
			temporary = head->next;
			head->previous->next = temporary;
			head->next->previous = head->previous;
			delete head;
			sizeOfList--;
			head = temporary;
			return true;
		}
	} else {
		return false;
	}
}
bool CircularDLL::removeTail() {
	if (this->size() > 0) {
		if (this->size() == 1) {
			delete tail;
			sizeOfList--;
			head = NULL;
			current = NULL;
			temporary = NULL;
			tail = NULL;
			return true;
		} else {
			temporary = tail->previous;
			tail->previous->next = tail->next;
			tail->next->previous = tail->previous;
			delete tail;
			sizeOfList--;
			tail = temporary;
			return true;
		}
		return false;
	} else {
		return false;
	}
}

bool CircularDLL::removeAt(int index) {
	if (index >= 0) {
		current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		if (current == head && current != NULL) {
			current->previous->next = current->next;
			current->next->previous = current->previous;
			head = current->next;
			delete current;
			sizeOfList--;
			return true;
		}
		if (current == tail && current != NULL) {
			current->previous->next = current->next;
			current->next->previous = current->previous;
			tail = current->previous;
			delete current;
			sizeOfList--;
			return true;
		}
		current->previous->next = current->next;
		current->next->previous = current->previous;
		delete current;
		sizeOfList--;
		return true;
	} else {
		return false;
	}
}
void CircularDLL::clear() {
	cout << "Clear called. Size: " << sizeOfList << "...";
	if (sizeOfList > 0) {
		if (sizeOfList == 1) {
			cout << "deleting for size=1";
			delete head;
			sizeOfList--;
			head = NULL;
			current = NULL;
			temporary = NULL;
			tail = NULL;
			return;
		} else {
			cout << "deleting for size>1 = " << sizeOfList;
			current = head;
			int count = sizeOfList;
			for (int i = 0; i < count; i++) {
				temporary = current;
				if (current->next != NULL) {
					current = current->next;
				}
				cout << temporary->name << " deleted";
				delete temporary;
				sizeOfList--;
			}

		}

	}else{
		cout << "Size already 0";
	}
	head = NULL;
	current = NULL;
	temporary = NULL;
	tail = NULL;
	cout << "All pointers set to NULL" << endl;
}
int CircularDLL::size() {
	return sizeOfList;
}
string CircularDLL::atFromHead(int index) {
	if (index >= 0) {
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
	if (index >= 0) {
		current = tail;
		for (int i = 0; i < index; i++) {
			current = current->previous;
		}
		return current->name;
	} else {
		return "invalid";
	}
}

} /* namespace std */
