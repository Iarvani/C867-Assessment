#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:

	//accessors / getters
	int getAge();
	int* getDaysInCourse();
	
	string getEmail();
	string getFirstName();
	string getLastName();
	string getStudentId();
	Degree getDegree();
	Degree getDegreeProgram();
	
	//mutators / setters
	void setStudentId(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(int);
	void setDaysInCourse(int[3]);
	void setDegree(Degree);
	void print();
		
	//constructor
	Student();
	Student(string, string, string, string, int, int*, Degree);
	
	//deconstructor
	~Student();
private:
	int Age;
	int DaysInCourse[3];
	string Email;
	string FirstName;
	string LastName;
	string StudentId;
	Degree DegreeType;
};


#endif
