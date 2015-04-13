/*
 * GPA.h
 *
 *  Created on: Apr 1, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_GPA_H_
#define TO_STUDENTS_STUDENT_CODE_GPA_H_

#include "GPAInterface.h"
#include "Student.h"
#include <fstream>
#include <iostream>

namespace std {

class GPA: public GPAInterface {
public:
	GPA();
	 ~GPA();

	map<unsigned long long int, StudentInterface*> getMap();
	set<StudentInterface*, Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();

	bool studentFileIsValid(string fileName);
	bool gradeFileIsValid(string fileName);
	void printMap();

private:
	map<unsigned long long int, StudentInterface*> students_map;
	set<StudentInterface*, Comparator> students_set;

};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_GPA_H_ */
