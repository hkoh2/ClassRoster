#pragma once
#ifndef student_h
#define student_h

#include <iostream>
#include <string>
#include <vector>
#include "degree.h"
using namespace std;


class Student {

	public:
		Student();
		~Student();
		Student(string id, string firstName, string lastName, string email, int age, int day1, int day2, int day3, DegreeProgram degree);
		string GetId() { return id; };
		string GetFirstName() { return firstName;  };
		string GetLastName() { return lastName;  };
		string GetEmail() { return email;  };
		int GetAge() { return age; };
		int* GetDaysComplete() { return daysComplete; };
		DegreeProgram GetDegree() { return degree; };

		void SetId(string id);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmail(string email);
		void SetAge(int age);
		void SetDaysComplete(int days[]);
		void SetDaysComplete(int day1, int day2, int day3);
		void SetDegree(DegreeProgram degree);
		void print();

	private:
		string id;
		string firstName;
		string lastName;
		string email;
		int age;
		int daysComplete[3];
		DegreeProgram degree;
};

#endif
