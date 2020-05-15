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
	
	//mutators / setters
	void setAge(int);
	void setDaysInCourse(int[3]);
	void setEmail(string);
	void setFirstName(string);
	void setLastName(string);
	void setStudentId(string);
	void setDegree(Degree);
	void print();
	Degree getDegreeProgram();
	
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