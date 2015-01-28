//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once
#include <string>

using namespace std;

template<class T>
class LinkedListInterface
{

public:

	LinkedListInterface(void){};
	virtual ~LinkedListInterface(void){};
	
	/*
		insertHead

		A node with the given value should be inserted at the beginning of the list.

		Do not allow duplicate values in the list.
	 */
	virtual void insertHead(T value) = 0;

	/*
		insertTail

		A node with the given value should be inserted at the end of the list.

		Do not allow duplicate values in the list.
	 */
	virtual void insertTail(T value) = 0;

	/*
		insertAfter

		A node with the given value should be inserted immediately after the
		node whose value is equal to insertionNode.

		A node should only be added if the node whose value is equal to
		insertionNode is in the list. Do not allow duplicate values in the list.
	 */
	virtual void insertAfter(T value, T insertionNode) = 0;
	
	/*
		remove

		The node with the given value should be removed from the list.

		The list may or may not include a node with the given value.
	 */
	virtual void remove(T value) = 0;

	/*
		clear

		Remove all nodes from the list.
	 */
	virtual void clear() = 0;

	/*
		at

		Returns the value of the node at the given index. The list begins at
		index 0.

		If the given index is out of range of the list, throw an out of range exception.
	 */
	virtual T at(int index) = 0;

	/*
		size

		Returns the number of nodes in the list.
	 */
	virtual int size() = 0;

};
