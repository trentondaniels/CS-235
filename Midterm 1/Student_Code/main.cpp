/*
 * main.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: Jason
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "CircularDLL.h"

using namespace std;

int main() {

	CircularDLL roster;
	int choice, safeIndex;
	while (choice != 9) {
		cin >> choice;
		switch (choice) {
		case 1:
			string file_name;
			cin >> file_name;
			roster = listFromFile(file_name);
			break;
		case 2:
			displayRoster(roster);
			break;
		case 3:
			string name;
			if (prependNameToRoster(name, roster)) {
				cout << name << " added" << endl;
			} else {
				cout << name << " could not be added" << endl;
			}
			break;
		case 4:
			string name;
			if (appendNameToRoster(name, roster)) {
				cout << name << " added" << endl;
			} else {
				cout << name << " could not be added" << endl;
			}
			break;
		case 5:
			int index;
			if (removeByIndex(index, roster)) {

			}
			break;
		case 6:
			shuffleRoster(roster);
			break;
		case 7:
			int count;
			cin >> count;
			safeIndex = calculateSafeIndex(roster, count);
			break;
		case 8:
			int count;
			cin >> count;
			dispatchBand(roster, count);
			break;
		case 9:
			return 0;
			break;
		}

	}
	return 0;
}

CircularDLL listFromFile(string file_name) {
	CircularDLL roster;
	ifstream fileStream;
	fileStream.open(file_name.c_str());
	if (fileStream.is_open()) {
		string name;
		while (fileStream >> name) {
			roster.insertTail(name);
		}
	}

	return roster;
}

void displayRoster(CircularDLL roster) {
	for (int i = 0; i < roster.size(); i++) {
		cout << i << ": " << roster.atFromHead(i);
	}
}

bool prependNameToRoster(string name, CircularDLL roster) {
	return (roster.insertHead(name));

}

bool appendNameToRoster(string name, CircularDLL roster) {
	return (roster.insertTail(name));
}

bool removeByIndex(int index, CircularDLL roster) {
	return (roster.removeAt(index));
}

void shuffleRoster(CircularDLL &roster) {
	CircularDLL result;
	int random;
	while (roster.size() > 0) {
		random = rand() % roster.size;
		result.insertHead(roster.atFromHead(random));
	}
	roster = result;
}

int calculateSafeIndex(CircularDLL roster, int count_in) {
	int count = count_in, safeIndex;
	bool acceptable = false;
	if (count >= 1 && count <= roster.size()) {
		acceptable = true;
	}
	while (!acceptable) {
		cout << "Count invalid. Please try again..." << endl;
		cin >> count;
	}

	CircularDLL test = roster;
	int tracker = 0;
	while (test.size() > 1) {
		cout << "Removed: " << test.atFromHead(tracker + count);
		test.removeAt(tracker + count);
		tracker += count - 1;
	}
	cout << "Survivor: " << test.atFromHead(0);
	bool indexFound = false;
	while (!indexFound) {
		if (roster.atFromHead(safeIndex) != test.atFromHead(0)) {
			safeIndex++;
		} else {
			indexFound = true;
		}
	}

	return safeIndex;
}

void dispatchBand(CircularDLL &roster, int count_in) {
	int count = count_in;
	bool acceptable = false;
	if (count >= 1 && count <= roster.size()) {
		acceptable = true;
	}
	while (!acceptable) {
		cout << "Count invalid. Please try again..." << endl;
		cin >> count;
	}
	int tracker = 0;
	while (test.size() > 1) {
		cout << "Removed: " << test.atFromHead(tracker + count);
		test.removeAt(tracker + count);
		tracker += count - 1;
	}
	cout << "Survivor: " << test.atFromHead(0);
}

