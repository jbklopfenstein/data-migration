#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student()//Empty constructor will set all to default values
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = "0";
	for (int i = 0; i < daysClassFinishArraySize; i++) this->days[i] = 0;

	//NOTE that neither Student constructor sets the DegreeType - the type of Degree is not known
}

Student::Student(string studentId, string firstName, string lastName, string email, string age, int days[])//The full constructor
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysClassFinishArraySize; i++) this->days[i] = days[i];
}

//getters
string Student::getStudentId()
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

string Student::getAge()
{
	return age;
}

int* Student::getDays()
{
	return days;
}

//setters
void Student::setStudentId(string studentId)
{
	this->studentId = studentId;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(string age)
{
	this->age = age;
}

void Student::setDays(int days[])
{
	for (int i = 0; i < daysClassFinishArraySize; i++)
		this->days[i] = days[i];
}

//The print method displays all fields Except the DegreeType!
void Student::print()
{
	cout << left << setw(5) << this->getStudentId();
	cout << left << setw(20) << this->getFirstName();
	cout << left << setw(20) << this->getLastName();
	cout << left << setw(30) << this->getEmail();
	cout << left << setw(20) << this->getAge();
	cout << left << setw(10) << this->getDays()[0];
	cout << left << setw(10) << this->getDays()[1];
	cout << left << setw(10) << this->getDays()[2];
}

Student::~Student()
{
//Student object does not declare anything dynamically for its own use here in this class(i.e. we haven't used the keyword "New" anywhere here!)
//So this destructor has an easy job; which is nothing
}

//NOTE THAT ALTHOUGH THIS 'ABSTRACT' CLASS SEEMS TO BE DOING A LOT OF WORK, AND WON'T USE IT,
//IT WON'T GO TO WASTE. ALL THE DERIVED SUBCLASSES WILL END UP USING IT!
