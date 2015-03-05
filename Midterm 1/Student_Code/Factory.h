#ifndef FACTORY_H_
#define FACTORY_H_
#include <cstddef>
#include "CircularDLLInterface.h"

using namespace std;

/*
	WARNING: Do not modify this document, including its name.
*/
//=======================================================================================
/*
	getLinkedList()

	Creates and returns an object whose class extends CircularDLLInterfface.h
	This should be an object of a class you have created.

	Example: If you made a class called "CircularDoubleLinkedList",
	you might say, "return new CircularDoubleLinkedList();".
*/

class Factory {
public:
	static CircularDLLInterface* getStudentList();
};
//=======================================================================================
#endif /* FACTORY_H_ */
