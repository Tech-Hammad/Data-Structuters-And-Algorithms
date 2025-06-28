#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
	string name;
	int priority;

	Student()
	{
		name = "";
		priority = 0;
	}
	Student(string n, int p)
	{
		name = n;
		priority = p;
	}

	bool operator==(const Student& other) const
	{
		return name == other.name && priority == other.priority;
	}

	friend ostream& operator<<(ostream& os, const Student& s) 
	{
		os << "(" << s.name << ", Priority: " << s.priority << ")";
		return os;
	}
};