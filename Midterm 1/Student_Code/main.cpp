/*
 * main.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: Jason
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "CircularDLL.h"

using namespace std;

bool prependNameToRoster(string name, CircularDLL &roster);
bool appendNameToRoster(string name, CircularDLL &roster);
int calculateSafeIndex(CircularDLL roster, int count_in);
void dispatchBand(CircularDLL &roster, int count_in);

void printMenu();
int main() {

	CircularDLL roster;
	roster.insertHead("Jason");
	roster.insertHead("Matt");
	roster.insertHead("Derrel");
	roster.insertHead("Spencer");
	roster.insertHead("Trevor");
	roster.insertHead("Andrew");
	int choice, safeIndex;
	while (choice != 9) {
		printMenu();
		cin >> choice;
		switch (choice) {
		case 1: {
			string file_name;
			cout << "Enter file name" << endl;
			cin.ignore();
			getline(cin, file_name);
			ifstream fileStream;
			fileStream.open(file_name.c_str());
			string name;
			if (fileStream.is_open()) {
				cout << "File opened" << endl;
				while (fileStream >> name) {
					roster.insertTail(name);
					cout << name << " inserted" << endl;
				}
				fileStream.close();
				cout << "File imported" << endl;
			} else {
				cout << "Could not open file" << endl;
			}
			break;
		}
		case 2: {
			cout << "Size: " << endl;
			cout << roster.size();
			cout << "..." << endl;
			if (roster.size() > 0) {
				cout << "Roster: " << endl;
				for (int i = 0; i < roster.size(); i++) {
					cout << i << ": " << roster.atFromHead(i) << endl;
				}
			} else {
				cout << "None" << endl;
			}

			break;
		}
		case 3: {
			string name;
			cout << "Enter name" << endl;
			cin >> name;
			if (prependNameToRoster(name, roster)) {
				cout << name << " added" << endl;
			} else {
				cout << name << " could not be added" << endl;
			}
			break;
		}
		case 4: {
			string name;
			cout << "Enter name" << endl;
			cin >> name;
			if (appendNameToRoster(name, roster)) {
				cout << name << " added" << endl;
			} else {
				cout << name << " could not be added" << endl;
			}
			break;
		}
		case 5: {
			int index;
			cout << "Enter Index" << endl;
			cin >> index;
			string name = roster.atFromHead(index);
			if (roster.removeAt(index)) {
				cout << name << " removed" << endl;
			} else {
				cout << "Could not remove" << name << endl;
			}
			break;
		}
		case 6: {
			vector<string> names;
			int random, size = roster.size();
			for (int i = 0; i < size; i++) {
				names.push_back(roster.atFromHead(i));
			}
			cout << "Calling clear()";
			roster.clear();
			cout << "Clear finished";
			for (int i = 0; i < size; i++) {
				random = rand() % names.size();
				roster.insertHead(names.at(random));
				names.erase(names.begin() + random);
			}

			break;
		}
		case 7: {
			int count;
			cout << "Enter count" << endl;
			cin >> count;
			cout << "Calling CSI";
			safeIndex = calculateSafeIndex(roster, count);
			cout << "CSI Finished. Safe Index = " << safeIndex << endl;
			break;
		}
		case 8: {
			int count;
			cout << "Enter count" << endl;
			cin >> count;
			dispatchBand(roster, count);
			break;
		}
		case 9: {
			return 0;
			break;
		}
		}

	}
	return 0;
}

void printMenu() {
	cout << endl << "1: Import File" << endl;
	cout << "2: Display Current Roster" << endl;
	cout << "3: Prepend Name To Roster" << endl;
	cout << "4: Append Name To Roster" << endl;
	cout << "5: Remove By Index" << endl;
	cout << "6: Shuffle Roster" << endl;
	cout << "7: Calculate Safe Index" << endl;
	cout << "8: Dispatch Band" << endl;
	cout << "9: Quit" << endl << endl;
}

bool prependNameToRoster(string name, CircularDLL &roster) {
	return (roster.insertHead(name));

}

bool appendNameToRoster(string name, CircularDLL &roster) {
	return (roster.insertTail(name));
}

int calculateSafeIndex(CircularDLL roster, int count_in) {
	cout << "CSI called...";
	int count = count_in, safeIndex = 0;
	bool acceptable = false;
	if (count >= 1 && count <= roster.size()) {
		acceptable = true;
	}
	while (!acceptable) {
		cout << "Count invalid. Please try again..." << endl;
		cin >> count;
		if (count >= 1 && count <= roster.size()) {
			acceptable = true;
		}
	}

	cout << "Count valid...";
	vector<string> names;
	int random, size = roster.size();
	for (int i = 0; i < size; i++) {
		names.push_back(roster.atFromHead(i));
	}
	int tracker = 0;
	while (roster.size() > 1) {
		cout << "Removed: " << roster.atFromHead(tracker + count) << endl;
		roster.removeAt(tracker + count);
		tracker += count - 1;
	}
	cout << "Survivor: " << roster.atFromHead(0);
	bool indexFound = false;
	while (!indexFound) {
		if (names.at(safeIndex) != roster.atFromHead(0)) {
			safeIndex++;
		} else {
			indexFound = true;
		}
	}
	cout << "Safe index found. Returning..." << endl;
	return safeIndex;
}

void dispatchBand(CircularDLL &roster, int count_in) {
	int count = count_in;
	bool acceptable = false;
	if(roster.size()<1){
		cout << "No names in roster" << endl;
		return;
	}
	if (count >= 1 && count <= roster.size()) {
		acceptable = true;
	}
	while (!acceptable) {
		cout << "Count invalid. Please try again..." << endl;
		cin >> count;
	}

	cout << "Count valid...";
	int tracker = 0;
	while (roster.size() > 1) {
		cout << "Removed: " << roster.atFromHead(tracker + count) << endl;
		roster.removeAt(tracker + count);
		tracker += count - 1;
	}
	cout << "Survivor: " << roster.atFromHead(0);
}

