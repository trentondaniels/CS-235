/*
 * QS.h
 *
 *  Created on: Apr 4, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_QS_H_
#define TO_STUDENTS_STUDENT_CODE_QS_H_

#include "QSInterface.h"
#include <sstream>

namespace std {

class QS: public QSInterface {
public:
	QS();
	virtual ~QS();

	void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray();
	int getSize();
	void addToArray(int value);
	bool createArray(int capacity);
	void clear();

	void swapValues(int *first, int *second);
	bool sorted(int left, int right);

private:
	int *data, timesAdded, dataSize;


};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_QS_H_ */
