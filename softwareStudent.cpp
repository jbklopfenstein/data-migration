#include <iostream>
#include <string>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() :Student()
{
	//This is the only work this constructor needs to do; the Student class will do the rest!!
	degreeProgram = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string email, string age, int days[], DegreeProgram degreeProgram)
	:Student(studentId, firstName, lastName, email, age, days)
{
	degreeProgram = SOFTWARE;
}

DegreeProgram SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;//Now we can do this - it's not virtual anymore
}

void SoftwareStudent::print()
{
	this->Student::print();//Call the print method fron the Student class
	cout << "SOFTWARE" << "\n";//This is the only thing left to display
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();//Call the super destructor from Student in case it needs to release something
	//Note: objects should not destroy themselves; only what they dynamically create FOR themselves
}