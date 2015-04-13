#include "Factory.h"
#include "AVL.h"

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getAVL()

	Creates and returns an object whose class extends BSTInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "AVL", you might say, "return new AVL();".
*/
AVLInterface * Factory::getAVL()
{
	AVLInterface* AVLObject = new AVL();
	return AVLObject;//Modify this line
}
