/*
 * QS.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: Jason
 */

#include "QS.h"

namespace std {

QS::QS() {
	timesAdded = 0;
	data = NULL;
	dataSize = 0;

}

QS::~QS() {
	// TODO Auto-generated destructor stub
}

void QS::swapValues(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

bool QS::sorted(int left, int right) {
	//cout << "sorted() called for " << left << "," << right;
	if (right < left) {
		//cout << "Invalid bounds";
		return false;
	}
	if (left == right - 1) {
		if (*(data + left) > *(data + right)) {
			swapValues(data + left, data + right);
		}
		return true;
	} else if (left == right) {
		return true;
	} else {
		int pivotIndex = partition(left, right, medianOfThree(left, right));
		return sorted(left, pivotIndex - 1) && sorted(pivotIndex + 1, right);
	}
}
void QS::sortAll() {
	//cout << "sortAll() called...";
	if (data == NULL || timesAdded < dataSize || dataSize <= 0) {
		//cout << "Invalid array: " << getArray();
		return;
	}

	if (sorted(0, dataSize - 1)) {
		//cout << "data sorted" << endl;
		return;
	} else {
		//cout << "data not sorted" << endl;
	}
}

int QS::medianOfThree(int left, int right) {
	if (data == NULL || left < 0 || right > (timesAdded - 1) || left >= right) {
		return -1;
	}

	int middle = (left + right) / 2;

	if (*(data + middle) > *(data + right)) {
		swapValues(data + middle, data + right);
	}

	if (*(data + left) > *(data + middle)) {
		swapValues(data + left, data + middle);
	}

	if (*(data + middle) > *(data + right)) {
		swapValues(data + middle, data + right);
	}

	return middle;

}

int QS::partition(int left, int right, int pivotIndex) {
	//cout << "partition() called for: " << left << "," << right << "," << pivotIndex << endl;
	//cout << "array size: " << timesAdded << ": "<< getArray();

	if (left > right || !(left < pivotIndex && pivotIndex < right)
			|| data == NULL || left < 0 || right > timesAdded
			|| right - left < 2) {
		//cout << "invalid input" << endl;
		return -1;
	}

	swapValues(data + left, data + pivotIndex);

	int *up = (data + left + 1), *down = (data + right - 1);

	do {
		while (*up <= *(data + left) && up != (data + right)) {
			up++;
		}

		while (*down > *(data + left) && down != (data + left)) {
			down--;
		}

		if (up < down) {
			swapValues(up, down);
		}

	} while (up < down);

	swapValues(data + left, down);

	//cout << "returning " << down-data << endl;
	//cout << "new array: " << getArray() << endl;
	return (down - data);
}

string QS::getArray() {
	if (timesAdded == 0 || data == NULL || dataSize == 0) {
		return "";
	}
	string result = "", intString = "";
	stringstream ss;
	for (int i = 0; i < timesAdded; i++) {
		ss << *(data + i);
		ss >> intString;
		ss.clear();
		result += intString;

		if (i < timesAdded - 1) {
			result += ",";
		}
	}

	return result;
}

int QS::getSize() {
	return timesAdded;
}

void QS::addToArray(int value) {
	if (timesAdded < dataSize) {
		*(data + timesAdded) = value;
		timesAdded++;
	}

}

bool QS::createArray(int capacity) {
	if (capacity <= 0) {
		return false;
	}
	data = new int[capacity];
	dataSize = capacity;
	timesAdded = 0;
	return true;
}

void QS::clear() {
	if (data == NULL || timesAdded <= 0) {
		return;
	}

	int *last = data + (timesAdded - 1);
	int *temp = data;
	cout << "Deleting Array size: " << dataSize << ": " << getArray();
	do {
		cout << "Deleting index: " << temp - data << " ";
		delete temp;
		temp++;

	} while (temp <= last);
	delete[] data;
	data = NULL;
	timesAdded = 0;
	dataSize = 0;
}

} /* namespace std */
