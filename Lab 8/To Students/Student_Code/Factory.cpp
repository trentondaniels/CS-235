#include "Factory.h"
#include "QS.h"
/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getQS()

	Creates and returns an object whose class extends QSInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "QS", you might say, "return new QS();".
*/
QSInterface * Factory::getQS()
{
	QSInterface *QSO = new QS();
  return QSO;//Modify this line
}
