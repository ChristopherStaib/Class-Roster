#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	Degree degreeType;

public:
	void setStudentID(string newStudentID);
    string getStudentID();
	void setFirstName(string newFirstName);
	string getFirstName();
	void setLastName(string newLastName);
	string getLastName();
	void setEmailAddress (string newEmailAddress);
	string getEmailAddress();
	void setAge(int newAge);
	int getAge();
	void setDaysToComplete(int newDaysToComplete[]);
	int* getDaysToComplete();
	virtual Degree getDegreeProgram() = 0;
	void setDegreeProgram(Degree newDegree);

	Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newDaysToComplete[3], Degree newDegree);
	virtual void print();
	~Student();

};