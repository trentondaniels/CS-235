#ifndef CIRCULARDLLINTERFACE_H_
#define CIRCULARDLLINTERFACE_H_

#include <string>

using namespace std;


/*
 * Warning: Do not modify this document in anyway, including its name.  Consequences of doing so
 * include the inability to compile with the grading test driver.  As warned in the Midterm packet,
 * any section of code that does not compile will not be graded.
 */
 
/**
 * The CircularDLLInterface defines basic operations performed on a circular double-linked list.
 * Your implementation of this interface must be a circular double-linked list.
 *
 * For this list, the word "invalid" is used as the return value of for atFromHead(int) and atFromTail(int) 
 * for invalid indices. You may check and reject the word "invalid" if you would like to make sure it is 
 * never a value in your list, but it is not necessary.  We will not attempt to insert "invalid".
 */
class CircularDLLInterface {
public:
	CircularDLLInterface(){};
	virtual ~CircularDLLInterface(){};

	/**
	 * Adds the given name to the beginning of the list so that
	 * atFromHead(0) == name and atFromTail(size() - 1) == name.
	 * After the operation, the size should have increased by 1.
	 *
	 * returns true if successful.
	 * returns false if the same name already exists.
	 */
	virtual bool insertHead(string name) = 0;

	/**
	 * Adds the given name to the end of the list so that
	 * atFromHead(size() - 1) == name and atFromTail(0) == name.
	 * After the operation, the size should have increased by 1.
	 *
	 * returns true if successful, false otherwise.
	 * returns false if the same name already exists.
	 */
	virtual bool insertTail(string name) = 0;

	/**
	 * Inserts the given name into the given index of the list so that
	 * atFromHead(index) == name.  All values should shift down one index
	 * to accommodate the new value.  After the operation, the size should
	 * have increased by 1.
	 *
	 * returns true if insert was successful.
	 * returns false if the same name already exists.
	 * returns false if the given index was out of range.
	 */
	virtual bool insertAt(string name, int index)  = 0;

	/**
	 * Removes the value at the beginning of the list.  After this operation
	 * size() should return a value 1 less than before and all values should
	 * shift 1 index forward. If only one item remains, the head and tail 
	 * pointers should be returned a NULL state.
	 *
	 * returns true if the removal occurred successfully.
	 * returns false if attempting to remove from an empty list.
	 */
	virtual bool removeHead() = 0;

	/**
	 * Removes the value at the end of the list.  After this operation
	 * size() should return a value 1 less than before and all index values
	 * should remain unchanged. If only one item remains, the head and tail 
	 * pointers should be returned a NULL state.
	 *
	 * returns true if the removal occurred successfully.
	 * returns false if attempting to remove from an empty list.
	 */
	virtual bool removeTail() = 0;

	/**
	 * Removes the value at the given index measured from the beginning.
	 * index 0 is the beginning of the list.  After this removal the list size
	 * should be 1 less and all following values should shift forward by 1. 
	 * If only one item remains and index 0 is given, the head and tail 
	 * pointers should be returned a NULL state.
	 *
	 * returns true if the removal occurred successfully.
	 * returns false attempting to remove from an empty list.
	 * returns false if the index was out of the range.
	 */
	virtual bool removeAt(int index) = 0;

	/**
	 * Removes all nodes from the list and resets the state of the data structure
	 * to empty.  size() should return 0 after this operation.
	 */
	virtual void clear() = 0;

	/**
	 * As a reminder, size() and the at functions are used to read the contents
	 * of your list.  Without these we will not be able to determine the functionaliy
	 * of you list.
	 *
	 * returns the number of items in the list.
	 */
	virtual int size() = 0;

	/**
	 * Measured from the head, where the beginning is indexed as 0,
	 * and the end is indexed as size() - 1.
	 *
	 * returns the string located at the given index.
	 * returns the string "invalid" if an invalid index is given. See top comment.
	 */
	virtual string atFromHead(int index) = 0;

	/**
	 * Measured from the tail, where the end is indexed as 0,
	 * and the beginning is indexed as size() - 1.
	 *
	 * returns the string located at the given index.
	 * returns the string "invalid" if an invalid index is given. See top comment.
	 */
	virtual string atFromTail(int index) = 0;
};

#endif /* CIRCULARDLLINTERFACE_H_ */
