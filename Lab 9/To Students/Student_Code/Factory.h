#ifndef FACTORY_H_
#define FACTORY_H_
#include "AVLInterface.h"

using namespace std;

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
	getAVL()

	Creates and returns an object whose class extends BSTInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "AVL", you might say, "return new AVL();".
*/
class Factory
{
	public:
		static AVLInterface * getAVL();
};
//=======================================================================================
#endif /* FACOTORY_H_ */
