#pragma once
#include "StationInterface.h"
using namespace std;

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
class StationInterfaceExtra : public StationInterface
{
	public:
		StationInterfaceExtra(){}
		virtual ~StationInterfaceExtra(){}

		//Input-Restricted Deque----------------------------------------------
		/**
		 * Adds the current car to the IRDeque on the left side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the IRDeque is already full.
		 *
		 * @return true if the car is successfully added to the IRDeque; false otherwise
		 */
		virtual bool addToIRDequeLeft() = 0;

		/**
		 * Removes the leftmost car in the IRDeque and makes it the current car.
		 * Does nothing if there is already a current car or if the IRDeque already empty.
		 *
		 * @return true if the car is successfully removed from the IRDeque; false otherwise
		 */
		virtual bool removeFromIRDequeLeft() = 0;

		/**
		 * Removes the rightmost car in the IRDeque and makes it the current car.
		 * Does nothing if there is already a current car or if the IRDeque already empty.
		 *
		 * @return true if the car is successfully removed from the IRDeque; false otherwise
		 */
		virtual bool removeFromIRDequeRight() = 0;

		/**
		 * Returns the ID of the leftmost car in the IRDeque.
		 *
		 * @return the ID of the leftmost car in the IRDeque; -1 if the IRDeque is empty
		 */
		virtual int showTopOfIRDequeLeft() = 0;

		/**
		 * Returns the ID of the rightmost car in the IRDeque.
		 *
		 * @return the ID of the rightmost car in the IRDeque; -1 if the IRDeque is empty
		 */
		virtual int showTopOfIRDequeRight() = 0;

		/**
		 * Returns the number of cars in the IRDeque.
		 *
		 * @return the number of cars in the IRDeque
		 */
		virtual int showSizeOfIRDeque() = 0;

		//Output-Restricted Deque---------------------------------------------
		/**
		 * Adds the current car to the ORDeque on the left side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the ORDeque is already full.
		 *
		 * @return true if the car is successfully added to the ORDeque; false otherwise
		 */
		virtual bool addToORDequeLeft() = 0;

		/**
		 * Adds the current car to the ORDeque on the right side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the ORDeque is already full.
		 *
		 * @return true if the car is successfully added to the ORDeque; false otherwise
		 */
		virtual bool addToORDequeRight() = 0;

		/**
		 * Removes the leftmost car in the ORDeque and makes it the current car.
		 * Does nothing if there is already a current car or if the ORDeque already empty.
		 *
		 * @return true if the car is successfully removed from the ORDeque; false otherwise
		 */
		virtual bool removeFromORDequeLeft() = 0;

		/**
		 * Returns the ID of the leftmost car in the ORDeque.
		 *
		 * @return the ID of the leftmost car in the ORDeque; -1 if the ORDeque is empty
		 */
		virtual int showTopOfORDequeLeft() = 0;

		/**
		 * Returns the number of cars in the ORDeque.
		 *
		 * @return the number of cars in the ORDeque
		 */
		virtual int showSizeOfORDeque() = 0;
};
