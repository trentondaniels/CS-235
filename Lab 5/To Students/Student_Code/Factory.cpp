#include "Factory.h"
#include "Pathfinder.h"
//You may add #include statments here

using namespace std;

/*
	Unlike all other documents provided, you may modify this document slightly (but do not change its name)
*/
//=======================================================================================
/*
	createPathfinder()

	Creates and returns an object whose class extends PathfinderInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "Pathfinder", you might say, "return new Pathfinder();".
*/
PathfinderInterface* Factory::createPathfinder()
{
	PathfinderInterface *finder = new Pathfinder();
	return finder;//Modify this line
}
//=======================================================================================
