#include <iostream>
#include <string>
#include <sstream>

#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main() {

    int degreeNum = 0;
    
    Degree theDegree = Degree::SOFTWARE;
    Roster classRoster;
    string studentVal;
    string tempVar[9];
    Degree tempDegree = theDegree;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Israel,Arvanitas,iaravni@WGU.edu,36,33,44,53,SOFTWARE"
    };

    for (int i = 0; i < 5; i++) {
        string input = studentData[i];
        istringstream studentString(input);

        int x = 0;

        while (getline(studentString, studentVal, ',')) {
            tempVar[x] = studentVal;
            x += 1;
        }

        if (tempVar[8] == "NETWORK") {
            theDegree = Degree::NETWORK;
            tempDegree = theDegree;
        }
        else if (tempVar[8] == "SECURITY") {
            theDegree = Degree::SECURITY;
            tempDegree = theDegree;
        }
        else if (tempVar[8] == "SOFTWARE") {
            theDegree = Degree::SOFTWARE;
            tempDegree = theDegree;
        }

        classRoster.add(tempVar[0], tempVar[1], tempVar[2], tempVar[3], stoi(tempVar[4]), stoi(tempVar[5]), stoi(tempVar[6]), stoi(tempVar[7]), tempDegree);
    }
    
    cout << "                   ------------------------------------ WGU C867 Scripting and Programming Applications ----------------------------------------" << endl;
    cout << "                   ------------------------------------------------ By : Israel Arvanitas ------------------------------------------------------" << endl;
    cout << "                   ------------------------------------------------ Student # : 000915900 ------------------------------------------------------" << endl;
    cout << "                   -------------------------------------------------- Written with C++ ---------------------------------------------------------" << endl;
    cout << "                   --------------------------------------------- Written in MS Visual Studio ---------------------------------------------------" << endl;
    cout << endl << endl << endl << endl;

    classRoster.printAll();
    cout << endl << endl;
    
    classRoster.printInvalidEmails();
    cout << endl << endl;
    
    for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    cout << endl << endl;
    
    classRoster.printByDegreeProgram(Degree::SOFTWARE);
    cout << endl << endl;
    
    classRoster.remove("A3");
    classRoster.remove("A3");
    

    //expected: the above line should print a message saying such a student with this ID was not found.

return 0;
}
