#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Roster {
public:
    
    int index = 0;
    
    // Methods
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
    void printAll();
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    void remove(string studentID);
    void printByDegreeProgram(Degree degreeProgram);
    
    //decontructor
    ~Roster();
    
    //array for student objects
    Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};
#endif