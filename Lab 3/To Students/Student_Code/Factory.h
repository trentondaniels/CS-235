#pragma once
#include "ExpressionManagerInterface.h"
using namespace std;

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
	createExpressionManager()

	Creates and returns an object whose class extends ExpressionManagerInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "ExpressionManager", you might say, "return new ExpressionManager();".
*/
class Factory
{
	public:
		static ExpressionManagerInterface * createManager();
};
//=======================================================================================
