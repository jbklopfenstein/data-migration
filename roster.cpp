#include "roster.h"
using namespace std;
#include <string>

//Always define the empty constructor - it gets called by default of no other is specified
Roster::Roster()//The empty constructor sets to default values
{
	this->capacity = 0;
	this->lastIndex = -1;//Means Empty; 0 would be an array of one
	this->students = nullptr;
}

Roster::Roster(int capacity)//Sets a max capacity for the roster
{
	this->capacity = capacity;
	this->lastIndex = -1;//again, means empty
	this->students = new Student * [capacity];
}

Student* Roster::getStudentAt(int index)
{
	return students[index];
}

//calls a separate add() method at the end
void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		DegreeProgram degreeProgram;
		//Test if one of the 3 degree programs
		if ((row[1] == '1') || (row[1] == '4')) degreeProgram = SECURITY;
		else if ((row[1] == '3') || (row[1] == '5')) degreeProgram = SOFTWARE;
		else if (row[1] == '2') degreeProgram = NETWORK;
		else
		{
			cerr << "INVALID DEGREE PROGRAM. EXITING NOW\n";
			exit(-1);
		}

		//Parse through each student string delimiting on the comma
		//then extract each substring and store them in temp variables
		//Get the student ID, assign it to the temp holding variable
		int rhs = row.find(",");//the position of the comma is labeled as the right-hand side
		string sId = row.substr(0, rhs);//get every character before, and up to, the comma, but not including the comma, i.e. the ID

		//read first name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sFirstName = row.substr(lhs, rhs - lhs);

		//read last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sLastName = row.substr(lhs, rhs - lhs);

		//read email
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sEmail = row.substr(lhs, rhs - lhs);

		//read age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sAge = row.substr(lhs, rhs - lhs);

		//read days in each class
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days3 = stoi(row.substr(lhs, rhs - lhs));

		//Now Jam all the info in here, which will use the Add method below to process it according to each student degree constructor
		add(sId, sFirstName, sLastName, sEmail, sAge, days1, days2, days3, degreeProgram);
	}
	else //error and leave - we have exceeded capacity
	{
		cerr << "ERROR. LIST HAS EXCEEDED MAX CAPACITY\n EXITING NOW";
		exit(-1);
	}
}

//This method creates the student of proper type, then adds to the roster - all parsed values passed in
void Roster::add(string sId, string sFirstName, string sLastName, string sEmail, string sAge, int d1, int d2, int d3, DegreeProgram degreeProgram)
{
	//Make an array to get the days into the constructor
	int classDays[Student::daysClassFinishArraySize];
	classDays[0] = d1;
	classDays[1] = d2;
	classDays[2] = d3;
	if (degreeProgram == SECURITY) students[lastIndex] = new SecurityStudent(sId, sFirstName, sLastName, sEmail, sAge, classDays, degreeProgram);
	else if (degreeProgram == SOFTWARE) students[lastIndex] = new SoftwareStudent(sId, sFirstName, sLastName, sEmail, sAge, classDays, degreeProgram);
	else students[lastIndex] = new NetworkStudent(sId, sFirstName, sLastName, sEmail, sAge, classDays, degreeProgram);
}

void Roster::print_All()//roll thru array of students and print each
{
	//Note the fact that nothing in this code indicates which student subclass it will call the print method from. The compiler figures this out.
	//This is called runtime polymorphism.
	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}

bool Roster::remove(string ID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentId() == ID) //Student found
		{
			found = true;
			//delete it
			delete	this->students[i];
			//Move last student to this position - no gaps in array
			this->students[i] = this->students[lastIndex];
			lastIndex--;//decrement the roster by one
		}
	}
	if (!found) cout << "Student not found!!\n";
	return found;
}

void Roster::printDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentId() == studentID) //Student found
		{
			found = true;
			int* p = students[i]->getDays();
			cout << "\t" << "Average Days in class for student: " << studentID << " is " << (p[0] + p[1] + p[2])/3 << "\n";
 		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	cout << "Displaying invalid email addresses:\n";
	bool any = false;
	for (int i = 0; i <= 4; i++)
	{
		any = false;
		if (students[i]->getEmail().find(" ") != string::npos)
		{
			any = true;
			cout << "\t" << "Found a space in: " << students[i]->getEmail() << "\n";
		}
		
		if (students[i]->getEmail().find("@") == string::npos)
		{
			any = true;
			cout << "\t" << "Missing @ in: " << students[i]->getEmail() << "\n";
		}
		if (students[i]->getEmail().find(".") == string::npos)
		{
			any = true;
			cout << "\t" << "Missing period in: " << students[i]->getEmail() << "\n";
		}
	}
	if (any) cout << "\n";
	if (!any) cout << "\t" << "NONE" << "\n";
}

void Roster::printByDegreeProgram(DegreeProgram d)
{
	cout << "Printing students in degree program: " << degreeTypeString[d] << "\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getDegreeProgram() == d) this->students[i]->print();
	}
}

Roster::~Roster()//destroys all the students
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->students[i];//deletes each student first
	}
	delete students;//Deletes the dynamically allocated array of pointers of students
}

int main()
{
	cout << endl;
	cout << "Course Title: " << "Scripting and Programming - Applications C867 \n";
	cout << "Language Used: " << "C++ \n";
	cout << "WGU Student ID: " << "000821279 \n";
	cout << "Student Name: " << "Jeff Klopfenstein \n";
	cout << endl;

	int numStudents = 5;
	//Input is 8 long comma delimited strings
	string studentData[8] =
	{
		 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		 "A5,Jeff,Klopfenstein,jklopfe@wgu.edu,39,25,45,55,SOFTWARE"
	};

	Roster* rost = new Roster(numStudents);//Make the Roster
	cout << "Parsing data and adding students:\t";
	for (int i = 0; i < numStudents; i++)
	{
		rost->parseThenAdd(studentData[i]);//Parse each line, turn them into students, and add them to the roster
	}
	cout << "DONE\n";
	cout << "Displaying all Students:\n";
	cout << endl;

    //PRINT ALL
	rost->print_All();//Display all Students on the roster
	cout << endl;

	//INVALID EMAILS
	rost->printInvalidEmails();//spots email addresses that are in error and displays them
	cout << endl;

	//AVG DAYS IN COURSES PER STUDENT
	cout << "Printing average days to class completion for all students:\n";
	for (int i = 0; i < numStudents; i++)
	{
		rost->printDaysInCourse(rost->getStudentAt(i)->getStudentId());//prints the avg days of completion for a specified student
	}
	cout << endl;

	//PRINT BY DEGREE PROGRAM "SOFTWARE"
	rost->printByDegreeProgram(SOFTWARE);
	cout << "\n";
	cout << endl;

    //REMOVE A3
	cout << "Removing A3:\n";//Remove student with ID A3
	cout << endl;
	if (rost->remove("A3"))
	{
		rost->print_All();
		numStudents--;
	}
	cout << endl;

    //REMOVE A3 AGAIN
	cout << "Removing A3 again:\n";//Remove same item twice to check error condition
	if (rost->remove("A3")) rost->print_All();
	cout << endl;

	//Print only the students for each degree program
	//Note index is casted from an integer to a StudentProgram enum
	//for (int i = 0; i < 3; i++)  
	//{
	//	rost->printByDegreeProgram((DegreeProgram)i);
	//	cout << "\n";
	//}
	//cout << endl;

	rost->~Roster();

	system("pause");//Needed only to hold the console window up if using VSTUDIO
	return 0;

}//end main