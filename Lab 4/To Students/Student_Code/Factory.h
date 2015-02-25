#include "StationInterface.h"
#pragma once
/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
	createStation()

	Creates and returns an object whose class extends StationInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "Station", you might say, "return new Station();".
*/
class Factory
{
public:
	static StationInterface* createStation();
};

//=======================================================================================
