#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

/******************************************************
*  Adding student objects to the class roster array   *
******************************************************/

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {

	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

		classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
		index++;
	
	return;
}

/******************************************************
*  Rotate through array to print each element provided*
*  that the array is not a null value.                *
******************************************************/

void Roster::printAll() {

	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	return;
}

/******************************************************
*  Calculate average of days in 3 courses and print   *
*  the value.                                         *
******************************************************/

void Roster::printDaysInCourse(string studentID) {

	int avgerage = 0;
	int maxVal = 3;

	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {

			int* daysInCourse = classRosterArray[i]->getDaysInCourse();

			for (int x = 0; x < maxVal; x++) {
				avgerage += daysInCourse[x];
			}

			cout << "The student " << classRosterArray[i]->getStudentId() << "'s average number of days in courses is " << (avgerage / maxVal) << endl;
			break;
		}
	}
	return;
}

/******************************************************
*  Check for characters @ before '.' and no 'space'   *
*  in array email values.                             *
******************************************************/

void Roster::printInvalidEmails() {

	for (int i = 0; i < 5; i++) {

		string email = classRosterArray[i]->getEmail();
		bool isBad = false;
		size_t found = email.find("@");

		if (found != string::npos) {
			found = email.find(".");
			
			if (found != string::npos) {
				found = email.find(" ");
				
				if (found == string::npos) {
					isBad = true;
				}
			}
		}

		if (!isBad) {
			cout << email << " : invalid email address." << endl;
		}
	}
	return;
}

/******************************************************
*  checks studentid(sID) to the studentid arguement   *
*  and deletes that position in the array.            *
******************************************************/

void Roster::remove(string studentID) {

	bool iDfound = false;
	string sID = "";
	int i = 0;
	
	while (i < 5) {
		
		if (classRosterArray[i] != nullptr) {
			sID = classRosterArray[i]->getStudentId();
		}
		if (sID == studentID) {

			classRosterArray[i] = nullptr;
			cout << "Student #'" << studentID << "' was successfully removed." << endl;
			delete classRosterArray[i];
			iDfound == true;
			return; // using return to break the loop, break; was not working correctly for some reason
		}
		i++;
	}

	if (iDfound == false) {
		cout << "Student #'" << studentID << "' could not be found." << endl;
 	}

	return;
}

/******************************************************
*  pull the degree value from the roster and compair  *
*  to the arguement value.                            *
******************************************************/

void Roster::printByDegreeProgram(Degree degreeProgram) {
	

	for (int i = 0; i < 5; i++) {

		Degree studentDegree = classRosterArray[i]->getDegreeProgram();
		
		if (studentDegree == degreeProgram ) {
		
			cout << "Student in Software field : ";
			classRosterArray[i]->print();
			cout << endl;
		}
	}
	return;
}

Roster::~Roster() {}
