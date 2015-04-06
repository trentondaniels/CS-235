/*
 * QSInterface.h
 *
 *  Created on: May 1, 2014
 *  Last Updated on: March 30, 2015
 */

#ifndef QSINTERFACE_H_
#define QSINTERFACE_H_

#include <iostream>
#include <string>
using namespace std;

/*
 * WARNING: You may not modify any part of this document, including its name
 */

class QSInterface
{
	public:
		QSInterface(){}
		virtual ~QSInterface(){}

		/*
		 * sortAll()
		 *
		 * Sorts elements of the array.  After this function is called, every
		 * element in the array is less than or equal its successor.
		 *
		 * Does nothing if the array is empty.
		 */
		virtual void sortAll() = 0;

		/*
		 * medianOfThree()
		 *
		 * The median of three pivot selection has two parts:
		 *
		 * 1) Calculates the middle index by averaging the given left and right indices:
		 *
		 * middle = (left + right)/2
		 *
		 * 2) Then bubble-sorts the values at the left, middle, and right indices.
		 *
		 * After this method is called, data[left] <= data[middle] <= data[right].
		 * The middle index will be returned.
		 *
		 * Returns -1 if the array is empty, if either of the given integers
		 * is out of bounds, or if the left index is not less than the right
		 * index.
		 *
		 * @param left
		 * 		the left boundary for the subarray from which to find a pivot
		 * @param right
		 * 		the right boundary for the subarray from which to find a pivot
		 * @return
		 *		the index of the pivot (middle index); -1 if provided with invalid input
		 */
		virtual int medianOfThree(int left, int right) = 0;

		/*
		 * Partitions a subarray around a pivot value selected according to
		 * median-of-three pivot selection.
		 *
		 * The values which are smaller than the pivot should be placed to the left
		 * of the pivot; the values which are larger than the pivot should be placed
		 * to the right of the pivot.
		 *
		 * Returns -1 if the array is null, if either of the given integers is out of 			
		 * bounds, or if the first integer is not less than the second integer, or if the 			 
		 * pivot is not between the two boundaries.
		 *
		 * @param left
		 * 		the left boundary for the subarray to partition
		 * @param right
		 * 		the right boundary for the subarray to partition
		 * @param pivotIndex
		 * 		the index of the pivot in the subarray
		 * @return
		 *		the pivot's ending index after the partition completes; -1 if
		 * 		provided with bad input
		 */
		virtual int partition(int left, int right, int pivotIndex) = 0;

		/*
		 * Produces a comma delimited string representation of the array. For example: if my array
		 * looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0" 			 
		 * with no trailing comma.  The number of cells included equals the number of values added.
		 * Do not include the entire array if the array has yet to be filled.
		 *
		 * Returns an empty string, if the array is NULL or empty.
		 *
		 * @return
		 *		the string representation of the current array
		 */
		virtual string getArray() = 0;

		/*
		 * Returns the number of elements which have been added to the array.
		 */
		virtual int getSize() = 0;

		/*
		 * Adds the given value to the end of the array starting at index 0.
		 * For example, the first time addToArray is called,
		 * the give value should be found at index 0.
		 * 2nd time, value should be found at index 1.
		 * 3rd, index 2, etc up to its max capacity.
		 *
		 * If the array is filled, do nothing.
		 */
		virtual void addToArray(int value) = 0;

		/*
		 * Dynamically allocates an array with the given capacity.
		 * If a previous array had been allocated, delete the previous array.
		 * Returns false if the given capacity is non-positive, true otherwise.
		 *
		 * @param
		 *		size of array
		 * @return
		 *		true if the array was created, false otherwise
		 */
		virtual bool createArray(int capacity) = 0;

		/*
		 * Resets the array to an empty or NULL state.
		 */
		virtual void clear() = 0;
};



#endif /* QSINTERFACE_H_ */
