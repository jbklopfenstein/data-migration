#pragma once
#include <string>
#include "student.h"
using namespace std;

class NetworkStudent : public Student //A NetworkStudent is a type of Student, so it inherits from the Student class
{

public:
	//CONSTRUCTORS WILL CALL SUPERCONSTRUCTOR FROM Student
	NetworkStudent();
	NetworkStudent(
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
	~NetworkStudent();
};