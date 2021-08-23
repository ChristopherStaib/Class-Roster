#pragma once
#include "student.h"

using namespace std;

class SoftwareStudent : public Student {
public:
	//using base class' constructor
	using Student::Student;
	Degree getDegreeProgram();

private:
	Degree degreeType = SOFTWARE;
};
