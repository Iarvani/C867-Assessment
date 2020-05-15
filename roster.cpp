#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

/*void Roster::addIndex(int index) {
	index = this->index;
	return;
}*/

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {

	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	
	

		classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
		index++;
	
	//***************************** Array not saving information, return the saved array? *****************************************/
	//Try making a public variable for loop so indexs on main and roster cpp match.   
	return;
}

/*void Roster::printTest() {
	char userKey = ' ';
	cin >> userKey;
	while (userKey != 'q') {
		if (userKey == '1') {
			classRosterArray[0]->print();
			cin >> userKey;
		}
		if (userKey == '2') {
			classRosterArray[1]->print();
			cin >> userKey;
		}
		if (userKey == '3') {
			classRosterArray[2]->print();
			cin >> userKey;
		}
		if (userKey == '4') {
			classRosterArray[3]->print();
			cin >> userKey;
		}
		if (userKey == '5') {
			classRosterArray[4]->print();
			cin >> userKey;
		}
		else if (userKey == 'q') {
			break;
		}
	}
	return;
}*/

void Roster::printAll() {

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		classRosterArray[i]->print();
	}
	return;
}

void Roster::printDaysInCourse(string studentID) {

	int avgerage = 0;
	int maxVal = 3;

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {

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

void Roster::printInvalidEmails() {

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {

		string email = classRosterArray[i]->getEmail();
		bool isBad = false;
		// look for missing @, periods, or emails containing spaces
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

void Roster::remove(string studentID) {

	bool iDfound = false;

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		
		string sID = classRosterArray[i]->getStudentId();
		bool iDfound = false;
		
		if (sID == studentID) {
			classRosterArray[i] = nullptr;
			cout << "Student: " << studentID << " was successfully removed." << endl;
			iDfound = true;
			break;
		}
		else {
			iDfound = false;
		}
	}
	
	if (iDfound == false) {
		cout << "Student ID '" << studentID << "' not found." << endl;
	}
	return;
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {

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
