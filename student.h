#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	const static int daysClassFinishArraySize = 3;

protected://protected items are visible to derived classes(child classes of this one can see these)
	string studentId;
	string firstName;
	string lastName;
	string email;
	string age;
	int days[daysClassFinishArraySize];//days to finish each class will be an array of size 3
	DegreeProgram degreeProgram;//Just put this Here - there are virtual methods implying its existence

public://items are visible everywhere in the application

	Student();//empty constructor
	//full constructor(this does not include degreeType though - the subclasses will do this)
	//keep in mind this is an abstract, meaning it cannot create any objects, due to having virtual methods in it
	Student(string studentId, string firstName, string lastName, string email, string age, int days[]);

	//getters for each instance field
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getAge();
	int* getDays();
	virtual DegreeProgram getDegreeProgram() = 0;//VIRTUAL; will not actually instantiate a Degree object

	//setters
	void   setStudentId(string studentId);
	void   setFirstName(string firstName);
	void   setLastName(string lastName);
	void   setEmail(string email);
	void   setAge(string age);
	void   setDays(int days[]);

	virtual void print() = 0;//this will display everything about a Student, Except for their degreeType(which it does not know, since that is the purpose of the subclasses)

	//The destructor
	~Student();

};