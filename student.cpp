#include <iostream>
#include <string>

#include "degree.h"
#include "student.h"

using namespace std;

// Accessor method definitions

string Student::getStudentId()
{
	return StudentId;
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
}

string Student::getEmail()
{
	return Email;
}

int Student::getAge()
{
	return Age;
}

int* Student::getDaysInCourse()
{
	return DaysInCourse;
}

Degree Student::getDegree()
{
	return Degree();
}

Degree Student::getDegreeProgram()
{
	return DegreeType;
}

// mutator method definitions

void Student::setStudentId(string studentId)
{
	StudentId = studentId;
	return;
}

void Student::setFirstName(string firstName)
{
	FirstName = firstName;
	return;
}

void Student::setLastName(string lastName)
{
	LastName = lastName;
	return;
}

void Student::setEmail(string email)
{
	Email = email;
	return;
}

void Student::setAge(int age)
{
	Age = age;
	return;
}

void Student::setDaysInCourse(int* daysInCourse)
{
	for (int i = 0; i < 3; i++) {

		DaysInCourse[i] = daysInCourse[i];
	}
	return;
}

void Student::setDegree(Degree degreeType)
{
	DegreeType = degreeType;
	return;
}

// print method definition

void Student::print()
{
	int* daysInCourse = getDaysInCourse();

	cout << getStudentId() << "   ";
	cout << "First Name: " << getFirstName() << "   ";//tab = 3 spaces, tab button, or "/t" 
	cout << "Last Name: " << getLastName() << "   ";
	cout << "Email: " << getEmail() << "   ";
	cout << "Age: " << getAge() << "   ";
	cout << "daysInCourse: { " << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << " }   ";
	cout << "Degree Program: ";

	if (getDegree() == Degree::SECURITY) {

		cout << "Security";
	}

	else if (getDegree() == Degree::NETWORK) {

		cout << "Network";
	}

	else if (getDegree() == Degree::SOFTWARE) {

		cout << "Software";
	}

	cout << endl;
	return;
}

// Contructor

Student::Student() {

}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysInCourse[3], Degree degreeType)
{
	setStudentId(studentId);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setDaysInCourse(daysInCourse);
	setDegree(degreeType);
}

// Deconstructor

Student::~Student()
{
}