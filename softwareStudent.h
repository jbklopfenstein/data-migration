#pragma once
#include <string>
#include "student.h"
using namespace std;

class SoftwareStudent : public Student //A SoftwareStudent is a type of Student, so it inherits from the Student class
{

public:
	//CONSTRUCTORS WILL CALL SUPERCONSTRUCTOR FROM Student
	SoftwareStudent();
	SoftwareStudent(
		string studentId,
		string firstName,
		string lastName,
		string email,
		string age,
		int days[],
		DegreeProgram degreeProgram
	);
	//The following virtual methods(from within Student), become overridden in this class, because we CAN create a DegreeType object!
	DegreeProgram getDegreeProgram();
	void print();

	//DESTRUCTOR WILL CALL SUPERDESTRUCTOR FROM STUDENT
	~SoftwareStudent();
};