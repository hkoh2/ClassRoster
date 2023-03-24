#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "degree.h"
using namespace std;


Student::Student() {
	// default constructor also used as a blank student when students are deleted
	this->id = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->daysComplete[0] = 0;
	this->daysComplete[1] = 0;
	this->daysComplete[2] = 0;
	this->degree = SECURITY;
}

Student::Student(string id, string firstName, string lastName, string email, int age, int day1, int day2, int day3, DegreeProgram degree) {
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->daysComplete[0] = day1;
	this->daysComplete[1] = day2;
	this->daysComplete[2] = day3;
	this->degree = degree;
}

Student::~Student() {
	// ...
}

void Student::SetId(string id) {
	this->id = id;

}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;

}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;

}
void Student::SetEmail(string email) {
	this->email = email;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysComplete(int days[]) {
	int i;
	for (i = 0; i < 3; i++) {
		this->daysComplete[i] = days[i];
	}
}

void Student::SetDaysComplete(int day1, int day2, int day3) {
	this->daysComplete[0] = day1;
	this->daysComplete[1] = day2;
	this->daysComplete[2] = day3;
}

void Student::SetDegree(DegreeProgram degree) {
	this->degree = degree;
}

void Student::print() {
	string degreeType[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

	cout << id << "\t" << firstName << "\t" << lastName << "\t" << age << "\t{";
	for (int i = 0; i < 3; i++) {
		cout << this->daysComplete[i];
		if (i >= 2) {
			break;
		}
		cout << ",";
	}
	cout << "}\t" << degreeType[degree] << endl;
}
