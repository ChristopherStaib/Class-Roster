#include <iostream>
#include <string>
#include "roster.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //Project Info
    cout << "Course: SCRIPTING AND PROGRAMMING APPLICATIONS C867, Language: C++, ID: 001174711, Name: Christopher Staib" << endl;

    Roster* classRoster = new Roster();

    const string studentData[5] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Christopher,Staib,cstaib@wgu.edu,21,30,25,57,SOFTWARE"
    };

    //use stringstream to separate students info into a vector
    for (int i = 0; i < 5; ++i) {
        stringstream ss(studentData[i]);
        vector<string> inputStudent;

        //if stringstream works properly, remove ',' char delimiter and append new value or string
        while (ss.good()) {
            string subString;
            getline(ss, subString, ',');
            inputStudent.push_back(subString);
        }


        Degree degreeType;
        string studentDegree = inputStudent.at(8); //set string to input string to be a placeholder for Degree enum before conversion

        //convert string to enum

        if (studentDegree == "SECURITY") {
            degreeType = SECURITY;
        }

        else if (studentDegree == "NETWORK") {
            degreeType = NETWORKING;
        }

        else {
            degreeType = SOFTWARE;
        }
        //receiving error for not converting string to int, read documentation on <string> library, solution is stoi
        classRoster->add(inputStudent.at(0), inputStudent.at(1), inputStudent.at(2), inputStudent.at(3), stoi(inputStudent.at(4)), stoi(inputStudent.at(5)), stoi(inputStudent.at(6)), stoi(inputStudent.at(7)), degreeType);
    }

    classRoster->printAll();
    classRoster->printInvalidEmails();

    cout << endl;

    for (int j = 0; j < 5; ++j) {
        classRoster->printDaysInCourse(classRoster->classRosterArray[j]->getStudentID());
    }

    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);

    cout << endl;

    classRoster->remove("A3");
    classRoster->remove("A3");


    delete classRoster;
    return 0;
}

Roster::~Roster() {

}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
    int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            if (degreeType == SECURITY) {
                classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeType);
            }
            else if (degreeType == NETWORKING) {
                classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeType);
            }
            else {
                classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeType);
            }
            break;
        }
    }
}

void Roster::remove(string studentID) {
    int i = 0;
    bool isFound = false;

    while (i < 5) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID()) == studentID) {
            cout << "Removed Student for Student ID: " << classRosterArray[i]->getStudentID() << endl;
            classRosterArray[i] = nullptr;
            isFound = true;

            break;
        }
        ++i;
    }
    if (isFound == false) {
        cout << "Error: A student with this ID was not found." << endl;
    }
}

void Roster::printAll() {
    int i = 0;
    cout << endl << "Student Data: " << endl << endl;
    while (i < 5) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
        ++i;
    }
    cout << endl;
}

void Roster::printDaysInCourse(string studentID) {
    int i = 0;
    
    while (i < 5) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID)) {
        int* daysToAverage = classRosterArray[i]->getDaysToComplete();
        double sumOfDays = 0.0;
        
        for (int i = 0; i < 3; ++i) {
            sumOfDays += daysToAverage[i];
        }

        cout << "Average days in course for Student ID " << classRosterArray[i]->getStudentID() << " : " << (sumOfDays / 3) << endl;
}
        ++i;
    }
}

void Roster::printInvalidEmails() {
    int i = 0;
    cout << "Printing Invalid Email Addresses: " << endl;
    while (i < 5) {
        Student* student = classRosterArray[i];
        string emailAddress = student->getEmailAddress();
        bool isError = false;
        
        //checks if @ and . are present and a space isnt present in the string
        if ((emailAddress.find('@') == string::npos) || (emailAddress.find('.') == string::npos) || (emailAddress.find(' ') != string::npos)) {
            isError = true;
            }

        if (isError == true) {
            cout << emailAddress << endl;
        }
        ++i;
    }
    cout << endl;
}

void Roster::printByDegreeProgram(int degreeType) {
    int i = 0;
    string degree;

    if (degreeType == 0) {
        degree = "SECURITY";
    }
    else if (degreeType == 1) {
        degree = "NETWORK";
    }
    else {
        degree = "SOFTWARE";
    }
    cout << "Printing by Degree Type (" << degree << ") :" << endl;
    while (i < 5) {
        Student* student = classRosterArray[i];

        if (student->getDegreeProgram() == degreeType) {
            student->print();
        }
        ++i;
    }
}