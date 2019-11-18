#include <iostream>
#include <string>
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent():Student()
{
	//This is the only work this constructor needs to do; the Student class will do the rest!!
	degreeProgram = SECURITY;
}

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string email, string age, int days[], DegreeProgram degreeProgram)
	:Student(studentId, firstName, lastName, email, age, days)
{
	degreeProgram = SECURITY;
}

DegreeProgram SecurityStudent::getDegreeProgram()
{
	return SECURITY;//Now we can do this - it's not virtual anymore
}

void SecurityStudent::print()
{
	this->Student::print();//Call the print method fron the Student class
	cout << "SECURITY" << "\n";//This is the only thing left to display
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();//Call the super destructor from Student in case it needs to release something
	//Note: objects should not destroy themselves; only what they dynamically create FOR themselves
}