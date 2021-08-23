#include <string>
#include <iostream>
#include "student.h"


using namespace std;
//Accessors and Mutators
void Student::setStudentID(string newStudentID) {
    studentID = newStudentID;
}
string Student::getStudentID() {
    return studentID;
}

void Student::setFirstName(string newFirstName) {
    firstName = newFirstName; 
}
string Student::getFirstName() {
    return firstName;    
}

void Student::setLastName(string newLastName) {
    lastName = newLastName;
}
string Student::getLastName() {
    return lastName;  
}

void Student::setEmailAddress(string newEmailAddress) {
    emailAddress = newEmailAddress;
}
string Student::getEmailAddress() {
    return emailAddress;   
}

void Student::setAge(int newAge) {
    age = newAge;    
}
int Student::getAge() {
    return age;   
}

void Student::setDaysToComplete(int newDaysToComplete[]) {
    for (int i = 0; i < 3; ++i) {
        daysToComplete[i] = newDaysToComplete[i];
    }
}
int* Student::getDaysToComplete() {
    return daysToComplete;   
}

void Student::setDegreeProgram(Degree newDegree) {
    degreeType = newDegree;
}


//Constructors
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newDaysToComplete[3], Degree newDegree) {
    setStudentID(newStudentID);
    setFirstName(newFirstName);
    setLastName(newLastName);
    setEmailAddress(newEmailAddress);
    setAge(newAge);
    setDaysToComplete(newDaysToComplete);
    setDegreeProgram(newDegree);
}

//print Student Info
void Student::print() {
    //initialize pointer to array and enum to a string for print
    int* newDaysToComplete = getDaysToComplete();

    string degree;

    if (this->degreeType == SECURITY) {
        degree = "SECURITY";
    }
    else if (this->degreeType == NETWORKING) {
        degree = "NETWORK";
    }
    else {
        degree = "SOFTWARE";
    }
    //'\t' to tab the space instead of having to manually type it
    cout << "Student ID: " << getStudentID() << '\t';
    cout << "First Name: " << getFirstName() << '\t';
    cout << "Last Name: " << getLastName() << '\t';
    cout << "Age: " << getAge() << '\t';
    cout << "Days in Course: " << getDaysToComplete()[0] << ", " << getDaysToComplete()[1]  << ", "  << getDaysToComplete()[2] << '\t';
    cout << "Degree Program: " << degree << endl;
}
 
//Using Default Destructor
Student::~Student() {
    
}

