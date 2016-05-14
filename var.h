#pragma once

#include <iostream>
#include <string>
#include <climits>

using namespace std;

enum TYPE {BET_INT, BET_DOUBLE, BET_STRING};

#pragma pack(push, 1)

class var
{
	//int h;
	double d;
	char* str;


	friend std::ostream& operator<<(std::ostream &os, const var& va);
	friend std::istream& operator>>(std::istream &is, var& va);

	const int TypeDetector(const string &str);

public:

	var() : str(""), d(DBL_MIN) {}
	var(int d) : d(d), str("") {}
	var(double d) :d(d),  str("") {}
	var(char* str) :str(str),  d(DBL_MIN) {}
	
	const char at(const unsigned int &index);

	var& operator=(int a);

	var& operator=(double a);

	var& operator=(char* a);

	var& operator=(const var &obj);
	
	var operator+(const var &obj);

	var operator+(const int &obj);

	var operator+(const double &obj);

	var operator+(const char* &obj);
	
	var operator-(const var &obj);

	var& var::operator*(const var &obj);

	var& var::operator/(const var &obj);
};


#pragma pack(pop)