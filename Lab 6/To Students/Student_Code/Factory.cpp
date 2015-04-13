#include "Factory.h"
#include "BST.h"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getBST()

	Creates and returns an object whose class extends BSTInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "BST", you might say, "return new BST();".
*/
BSTInterface * Factory::getBST()
{
	BSTInterface *Tree = new BST();
	return Tree;//Modify this line
}
