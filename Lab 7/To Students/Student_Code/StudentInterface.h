//IT IS FORBIDDEN TO MODIFY ANY PART OF THIS DOCUMENT

#pragma once
#include <string>

using namespace std;

class StudentInterface
{
	public:
		StudentInterface(void){};
		virtual ~StudentInterface(void){};

		/*		
		 * getID()
		 *
		 * Returns the ID of the Student.
		 */
		virtual unsigned long long int getID() = 0;

		/*
		 * getName()
		 *
		 * Returns the name of the Student
		 */

		virtual string getName() = 0;

		/*
		 * getGPA()
		 *
		 * Returns the string representation of the Student's GPA.
		 */

		virtual string getGPA() = 0;

		/*
		 * addGPA()
		 *
		 * Incorporates the given course grade into the Student's overall GPA.
		 */

		virtual void addGPA(double classGrade) = 0;
		
		/*
		 * toString()
		 *
		 * The student object will be put into string representation. Student info will be
		 * ordered ID, name, address, phone number, and GPA. Each piece of information will
		 * be on its own line. GPA will not have a newline following it and the precision 
		 * of the GPA will be rounded to two decimal places. For example,
		 * 
		 * 123456789
		 * Ben Thompson
		 * 17 Russell St, Provo, UT 84606
		 * 555-555-5555
		 * 3.12
		 * 
		 * Returns a string representation of the student object There is no trailing new line.
		 */
		virtual string toString() = 0;
};

struct Comparator
{
	bool operator()(StudentInterface* student1, StudentInterface* student2)
	{
		return student1->getName() < student2->getName();
	}
};
