#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {

public:

	//accessors methods
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
	Degree getDegree();
	Degree getDegreeProgram();
	
	//mutators methods
	void setStudentId(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(int);
	void setDaysInCourse(int[3]);
	void setDegree(Degree);
	
	//method for print structure
	void print();
	
	//constructor
	Student();
	
	Student(string studentId, string firstName, string lastName, string email, int age, int daysInCourse[3], Degree degreeType);
	
	//deconstructor
	~Student();

private:
	
	string StudentId;
	string FirstName;
	string LastName;
	string Email;
	int Age;
	int DaysInCourse[3];
	Degree DegreeType;

};


#endif