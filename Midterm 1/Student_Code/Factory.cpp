#include "Factory.h"
#include "CircularDLL.h"


//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getStudentList()

	Creates and returns an object whose class extends CircularDLLInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "CircularDoubleLinkedList",
	you might say, "return new CircularDoubleLinkedList();".
*/
CircularDLLInterface* Factory::getStudentList() {
	CircularDLLInterface* list = new CircularDLL;
	return list;
}
//=======================================================================================
