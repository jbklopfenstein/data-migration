#include <iostream>
#include <string>
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() :Student()
{
	//This is the only work this constructor needs to do; the Student class will do the rest!!
	degreeProgram = NETWORK;
}

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string email, string age, int days[], DegreeProgram degreeProgram)
	:Student(studentId, firstName, lastName, email, age, days)
{
	degreeProgram = NETWORK;
}

DegreeProgram NetworkStudent::getDegreeProgram()
{
	return NETWORK;//Now we can do this - it's not virtual anymore
}

void NetworkStudent::print()
{
	this->Student::print();//Call the print method fron the Student class
	cout << "NETWORK" << "\n";//This is the only thing left to display
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();//Call the super destructor from Student in case it needs to release something
	//Note: objects should not destroy themselves; only what they dynamically create FOR themselves
}