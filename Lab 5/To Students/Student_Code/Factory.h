#include "PathfinderInterface.h"
#pragma once
/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
	createPathfinder()

	Creates and returns an object whose class extends PathfinderInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "Pathfinder", you might say, "return new Pathfinder();".
*/
class Factory
{
public:
	static PathfinderInterface* createPathfinder();
};

//=======================================================================================
