/*
 * Student.h
 *
 *  Created on: Apr 1, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_STUDENT_H_
#define TO_STUDENTS_STUDENT_CODE_STUDENT_H_

#include "StudentInterface.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>

namespace std {

class Student: public StudentInterface {
public:
	Student();
	Student(int ID, string name, string address, string phoneNumber);
	 ~Student();

	unsigned long long int getID();
	string getName();
	string getGPA();
	void addGPA(double classGrade);
	string toString();

	void setAddress(string address_in) {
		address = address_in;
	}
	void setPhoneNumber(string phoneNumber_in) {
		phoneNumber = phoneNumber_in;
	}
	void setName(string name_in) {
		name = name_in;
	}
	void setID(int ID_in) {
		ID = ID_in;
	}
	void setGPA(double GPA_in) {
		GPA = GPA_in;
	}

	void calculateGPA();



private:
	int ID;
	double GPA = 0.00;
	string name, address, phoneNumber;
	vector<double> grades;

};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_STUDENT_H_ */
