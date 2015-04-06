#include "Factory.h"
#include "GPA.h"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getGPA()

	Creates and returns an object whose class extends GPAInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "GPA", you might say, "return new GPA();".
*/
GPAInterface * Factory::getGPA()
{
	GPAInterface *GPAObject = new GPA();
	return GPAObject;//Modify this line
}
