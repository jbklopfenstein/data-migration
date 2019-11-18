#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

//Roster stores a  of Catalog of Students
class Roster
{
private:
	int lastIndex;//index of last student in roster - this effectively tracks how many entries are in the roster 
	int capacity;//the max size of the roster
	Student** students;//students is an array of pointers to students; therefore, **
public:
	Roster();//empty constructor creates roster and initializes all fields to default values
	Roster(int capacity);//this constructor does same, but sets the size

	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);//parses the strings, creates the Student objects, and adds them to the roster
	void add(string sId, string sFirstName, string sLastName, string sEmail, string sAge, int days1, int days2, int days3, DegreeProgram degreeProgram);//Called at the end
	void print_All();//prints all students in roster using each student's print() method
	bool remove(string studentId);//removes student based on ID
	void printDaysInCourse(string studentId);
	void printInvalidEmails();//locates and prints invalid email addresses
	void printByDegreeProgram(DegreeProgram degreeProgram);//prints students by specified degree 
	~Roster();//Destructor destroys the roster, releasing any resources it requested dynamically
};