/*
 * GPA.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: Jason
 */

#include "GPA.h"

namespace std {

GPA::GPA() {
	// TODO Auto-generated constructor stub

}

GPA::~GPA() {
	this->clear();
}

map<unsigned long long int, StudentInterface*> GPA::getMap() {
	return students_map;
}
set<StudentInterface*, Comparator> GPA::getSet() {
	return students_set;
}

void GPA::printMap() {
	//cout << "printMap() called...";
	typedef map<unsigned long long int, StudentInterface*>::iterator it;
	it i;
	for (i = students_map.begin(); i != students_map.end(); i++) {
		if (i->second != NULL) {
			//cout << i->second->toString();
		} else {
			//cout << i->first << " is NULL" << endl;
		}
	}

}

bool GPA::studentFileIsValid(string fileName) {
	fstream file;
	stringstream ss;
	string idString;
	int id;
	string name, address, phoneNumber;
	file.open(fileName.c_str());
	if (!file.is_open()) {
		//cout << "invalid filename" << endl;
		return false;
	}

	while (getline(file, idString)) {
		////cout << id << " found...";
		if (std::isdigit(idString[0])) {
			stringstream ss;
			ss << idString;
			ss >> id;
		} else {
			//cout << "Invalid ID: " << idString << endl;
			return false;
		}
		getline(file, name);
		////cout << name << " found...";
		getline(file, address);
		////cout << address << " found...";
		getline(file, phoneNumber);
		////cout << phoneNumber << " found..." << endl;

		if (name == string() || address == string()
				|| phoneNumber == string()) {
			//cout << "Data: " << id << " ";
			//cout << name << " ";
			//cout << address << " ";
			//cout << phoneNumber << endl;
			//cout << "Not enough data in file" << endl;
			file.close();
			return false;
		}
		id = int();
		name = string();
		address = string();
		phoneNumber = string();
	}
	file.close();

	return true;

}

bool GPA::gradeFileIsValid(string fileName) {
	fstream file;
	stringstream ss;
	int id;
	string className, grade;
	file.open(fileName.c_str());
	if (!file.is_open()) {
		//cout << "Invalid file name" << endl;
		file.close();
		return false;
	}

	while (file >> id) {
		file.ignore();
		getline(file, className);
		getline(file, grade);

		if (id == int() || className == string() || grade == string()) {
			//cout << "Data: " << id << " " << className << " " << grade << endl;
			file.close();
			return false;
		}

		id = int();
		className = string();
		grade = string();

	}
	file.close();
	return true;
}

bool GPA::importStudents(string mapFileName, string setFileName) {
	if (studentFileIsValid(mapFileName) && studentFileIsValid(setFileName)) {
		fstream file;
		stringstream ss;
		int id;
		string name, address, phoneNumber;
		file.open(mapFileName.c_str());

		while (file >> id) {
			file.ignore();
			getline(file, name);
			getline(file, address);
			getline(file, phoneNumber);
			file.sync();
			students_map[id] = new Student(id, name, address, phoneNumber);
			////cout << students_map[id]->getName() << " added to map" << endl;
		}
		file.close();

		file.open(setFileName.c_str());

		while (file >> id) {
			file.ignore();
			getline(file, name);
			getline(file, address);
			getline(file, phoneNumber);
			file.sync();
			students_set.insert(new Student(id, name, address, phoneNumber));
			////cout << name << " added to set...";
		}
		file.close();

		return true;

	} else {
		return false;
	}
}

bool GPA::importGrades(string fileName) {
	//cout << "importGrades() called...";
	if (!gradeFileIsValid(fileName)) {

		return false;
	}
	//cout << "file valid...";
	fstream file;
	stringstream ss;
	unsigned long long int id, counter = 0;
	string className, grade;
	StudentInterface *student = NULL;
	file.open(fileName.c_str());
	typedef set<StudentInterface*, Comparator>::iterator it;
	while (file >> id) {
		file.ignore();
		getline(file, className);
		getline(file, grade);

		if (students_map[id] == NULL) {
			students_map.erase(id);
			it iterator;
			for (iterator = students_set.begin();
					iterator != students_set.end(); iterator++) {
				if ((*iterator)->getID() == id) {
					student = *iterator;
				}
			}
		} else {
			student = students_map[id];
		}

		if (grade == "A") {
			student->addGPA(4.0);
		} else if (grade == "A-") {
			student->addGPA(3.7);
		} else if (grade == "B+") {
			student->addGPA(3.4);
		} else if (grade == "B") {
			student->addGPA(3.0);
		} else if (grade == "B-") {
			student->addGPA(2.7);
		} else if (grade == "C+") {
			student->addGPA(2.4);
		} else if (grade == "C") {
			student->addGPA(2.0);
		} else if (grade == "C-") {
			student->addGPA(1.7);
		} else if (grade == "D+") {
			student->addGPA(1.4);
		} else if (grade == "D") {
			student->addGPA(1.0);
		} else if (grade == "D-") {
			student->addGPA(0.7);
		} else if (grade == "E") {
			student->addGPA(0.0);
		}
		counter++;

	}
	file.close();
	//printMap();
	//cout << counter << " grades imported...Closing file" << endl;

	return true;

}

string GPA::querySet(string fileName) {
	//cout << "querySet() called...";
	fstream file;
	stringstream ss;
	int id;
	string result = "", IDString = "";
	StudentInterface *student = NULL;
	typedef set<StudentInterface*, Comparator>::iterator it;
	file.open(fileName.c_str());
	if (!file.is_open()) {
		//cout << "Invalid file name" << endl;
		file.close();
		return result;
	}

	while (file >> id) {
		it iterator;
		for (iterator = students_set.begin(); iterator != students_set.end();
				iterator++) {
			if ((*iterator)->getID() == id) {
				student = *iterator;
			}
		}
		if (student != NULL) {
			ss << student->getID();
			ss >> IDString;
			ss.clear();
			if (result != "") {
				if (result.find(IDString) == string::npos) {
					result += IDString + " " + student->getGPA() + " "
							+ student->getName() + "\n";
				}
			} else {
				result += IDString + " " + student->getGPA() + " "
						+ student->getName() + "\n";
			}

		}
	}
	file.close();
	return result;

}

string GPA::queryMap(string fileName) {
	//cout << "queryMap() called...";
	fstream file;
	stringstream ss;
	int id;
	string result = "", IDString = "";
	file.open(fileName.c_str());
	if (!file.is_open()) {
		//cout << "Invalid file name" << endl;
		file.close();
		return result;
	}

	while (file >> id) {
		if (students_map[id] == NULL) {
			students_map.erase(id);
		} else {
			ss << students_map[id]->getID();
			ss >> IDString;
			ss.clear();

			if (result != "") {
				if (result.find(IDString) == string::npos) {
					result += IDString + " " + students_map[id]->getGPA() + " "
							+ students_map[id]->getName() + "\n";
				}
			} else {
				result += IDString + " " + students_map[id]->getGPA() + " "
						+ students_map[id]->getName() + "\n";
			}
		}
	}
	file.close();
	return result;
}

void GPA::clear() {
	students_set.clear();
	students_map.clear();



}
}/* namespace std */
