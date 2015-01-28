#pragma once
#include "LinkedListInterface.h"

using namespace std;

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
	getLinkedList()

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList();".
*/
class Factory
{
	public:
		static LinkedListInterface<int>* getLinkedListInt();
		static	LinkedListInterface<string>* getLinkedListString();
		
};
//=======================================================================================
