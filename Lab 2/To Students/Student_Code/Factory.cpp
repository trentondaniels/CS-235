#include "Factory.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getLinkedListInt() and

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<int>();".
*/
LinkedListInterface<int> * Factory::getLinkedListInt()
{
	LinkedListInterface<int>* list = new LinkedList<int>();
	return list;
}

/*
	getLinkedListString() and

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<string>();".
*/
LinkedListInterface<string>* Factory::getLinkedListString()
{
	LinkedListInterface<string>* list = new LinkedList<string>();
		return list;
}
