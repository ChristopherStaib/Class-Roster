#pragma once
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

using namespace std;

class Roster {
public:
    ~Roster();
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
    void remove(string studentID);
    void printAll();
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(int degreeType);
    Student *classRosterArray[6] = { nullptr, nullptr, nullptr, nullptr, nullptr};
};