#include "roster.h"
#include "student.h"
using namespace std;


Roster::Roster() {
	int i;
	for (i = 0; i < 5; i++) {
		classRosterArray[i] = new Student();
	}
}

Roster::~Roster() {
	int i;
	for (i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
}

void Roster::parse(string student) {
	size_t rcursor;
	size_t lcursor;
	string id;
	string firstName;
	string lastName;
	string email;
	int age;
	int day1;
	int day2;
	int day3;
	string degree;

	// default degree
	DegreeProgram degreeType = SECURITY;

	rcursor = student.find(",");
	id = student.substr(0, rcursor);

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	firstName = student.substr(lcursor, rcursor - lcursor);

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	lastName = student.substr(lcursor, rcursor - lcursor);

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	email = student.substr(lcursor, rcursor - lcursor);

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	age = stoi(student.substr(lcursor, rcursor - lcursor));

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	day1 = stoi(student.substr(lcursor, rcursor - lcursor));

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	day2 = stoi(student.substr(lcursor, rcursor - lcursor));

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	day3 = stoi(student.substr(lcursor, rcursor - lcursor));

	lcursor = rcursor + 1;
	rcursor = student.find(",", lcursor);
	degree = student.substr(lcursor, rcursor - lcursor);

	if (degree == "SECURITY") {
		degreeType = SECURITY;
	}
	if (degree == "NETWORK") {
		degreeType = NETWORK;
	}
	if (degree == "SOFTWARE") {
		degreeType = SOFTWARE;
	}

	add(id, firstName, lastName, email, age, day1, day2, day3, degreeType);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int i;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetId() == "") {
			delete classRosterArray[i];
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
			break;
		}
	}
}

void Roster::remove(string studentID) {
	int i;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetId() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = new Student();
			cout << "Removed A3: " << endl;
			cout << endl;
			return;
		}
	}

	cout << studentID << " does not exists" << endl;
	cout << endl;
}

void Roster::printAll() {
	cout << "Displaying all students:" << endl;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetId() != "") {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	int total = 0;
	int avg;
	int* days;

	for (int i = 0; i < 5; i++) {
		Student* student = classRosterArray[i];
		if (student->GetId() == studentID) {
			days = student->GetDaysComplete();
			for (int i = 0; i < 3; i++) {
				total += days[i];
			}
		}
	}

	avg = total / 3;
	cout << "Student ID: " << studentID << ", average days in course is : " << avg << endl;
}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails: " << endl;
	cout << endl;

	bool atExists = false;
	bool dotExists = false;
	bool spaceExists = false;
	string email;

	int i;
	for (i = 0; i < 5; i++) {
		email = classRosterArray[i]->GetEmail();

		for (char letter : email) {
			if (letter == ' ') {
				spaceExists = true;
				break;
			}
			if (letter == '@') {
				atExists = true;
			}
			if (atExists && letter == '.') {
				dotExists = true;
			}
		}

		if (spaceExists || !(atExists && dotExists)) {
			cout << "Invalid Email: " << email << endl;
		}

		atExists = false;
		dotExists = false;
		spaceExists = false;
	}

	cout << endl;

}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	string degreeTypeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << endl;
	cout << "Showing students in degree program: " << degreeTypeStrings[degree] << endl;

	int i;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegree() == degree) {
			classRosterArray[i]->print();
		}
	}

	cout << endl;
}
