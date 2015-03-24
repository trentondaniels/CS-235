

#pragma once
#include "BSTInterface.h"

using namespace std;

/*
WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
getBST()

Creates and returns an object whose class extends BSTInterface.
This should be an object of a class you have created.

Example: If you made a class called "BST", you might say, "return new BST();".
*/
class Factory
{
public:
	static BSTInterface * getBST();
};
//=======================================================================================
