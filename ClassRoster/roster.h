#pragma once
#ifndef roster_h
#define roster_h

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Roster {
public:
	Roster();
	~Roster();
	void parse(string student);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
private:
	Student* classRosterArray[5];
};


#endif