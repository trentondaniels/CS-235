/*
 * Student.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: Jason
 */

#include "Student.h"

namespace std {

Student::Student() {

}

Student::Student(int ID, string name, string address, string phoneNumber) {
	this->ID = ID;
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

Student::~Student() {
	grades.clear();
}

unsigned long long int Student::getID() {
	//cout << "getID() called...";
	return ID;
}

string Student::getName() {
//cout << "getName() called...";
	return name;
}

string Student::getGPA() {
	//cout << "getGPA() called...";
	stringstream ss;
	ss << fixed << setprecision(2) << GPA;

	string result;
	ss >> result;
	return result;
}

void Student::calculateGPA() {
	//cout << "calculateGPA() called...";
	double total;
	for (int i = 0; i < grades.size(); i++) {
		total += grades.at(i);
	}

	if (grades.size() > 0) {
		GPA = total / grades.size();
	}else{
		GPA = 0.00;
	}

}

void Student::addGPA(double classGrade) {
	//cout << "addGPA called...";
	grades.push_back(classGrade);
	calculateGPA();
}

string Student::toString() {
	//cout << "toString() called...";
	stringstream ss;
	string result;
	ss << ID << endl;
	ss >> result;
	ss.clear();
	result += "\n" + name;
	result += "\n" + address;
	result += "\n" + phoneNumber;
	ss << fixed << setprecision(2) << GPA;
	string GPAString;
	ss >> GPAString;
	result += "\n" + GPAString;

	return result;
}

}

/* namespace std */
