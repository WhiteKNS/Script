#pragma once

#include <iostream>
#include <string>
#include <climits>

using namespace std;

enum TYPE {BET_INT, BET_DOUBLE, BET_STRING};

class var
{
	int h;
	double d;
	string str;

	friend std::ostream& operator<<(std::ostream &os, const var& va);
	friend std::istream& operator>>(std::istream &is, var& va);

	const int &TypeDetector(const string &str);

public:

	var() : str(""), h(INT_MIN), d(DBL_MIN) {}
	var(int a) : h(a), d(DBL_MIN), str("") {}
	var(double d) :d(d), h(INT_MIN), str("") {}
	var(std::string str) :str(str), h(INT_MIN), d(DBL_MIN) {}
	var(char* ch) : str(ch), h(INT_MIN), d(DBL_MIN) {}

	const char &at(const unsigned int &index);

	var& operator=(int a);

	var& operator=(double a);

	var& operator=(string a);

	var& operator=(const var &obj);

	var& operator+(const var &obj);

	var& operator-(const var &obj);
};


