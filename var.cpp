
#include "var.h"

const int& var::TypeDetector(const string &str)
{
	int counter = 0;
	unsigned int k = 0;
	if (str.at(0) == '-') k = 1;

	for (unsigned int i = k; i < str.length(); ++i)
	{
		if (!isdigit(str.at(i)) && str.at(i) != '.') return BET_STRING;
		else if (str.at(i) == '.')
		{
			counter++;
			if (2 == counter) return BET_STRING;
		}
	}

	if (1 == counter) return BET_DOUBLE;
	else  return BET_INT;

}

const char& var::at(const unsigned int &index)
{
	if (index >= str.length()) return ' ';
	return str.at(index);
}


var& var::operator=(int a)
{
	h = a;
	d = DBL_MIN;
	str.clear();
	return *this;
}

var& var::operator=(double a)
{
	d = a;
	h = INT_MIN;
	str.clear();
	return *this;
}

var& var::operator=(string a)
{
	str = a;
	d = DBL_MIN;
	h = INT_MIN;
	return *this;
}


var& var::operator+(const var &obj)
{
	var obj2 = *this;
	if ((!obj.str.empty() && str.empty()) || (obj.str.empty() && !str.empty()))
	{
		if (obj.h != INT_MIN) str += to_string(obj.h);
		else
		if (obj.d != DBL_MIN) str += to_string(obj.d);
		else str += obj.str;
		
	}
	else
	{
		if (obj.h != INT_MIN && h != INT_MIN) h += obj.h;
		else if (obj.d != DBL_MIN && d != DBL_MIN) d += obj.d;
		else  if (!obj.str.empty() && !str.empty())str += obj.str;
		else if (obj.h != INT_MIN && d != DBL_MIN) d += obj.h;
		else if (obj.d != DBL_MIN && h != DBL_MIN)
		{
			d = h;
			h = INT_MIN;
			d += obj.d;
		}
		else cout << "Uninitialized local variable" << endl;
	}
		return *this;
}

var& var::operator/(const var &obj)
{

	
	if ((!obj.str.empty() && str.empty()) || (obj.str.empty() && !str.empty()))
	{
		return *this;
	}
	else
	{
		cout << "var obj " << obj <<" d "<<d<<" h "<<obj.h<< endl;
		if (obj.h != INT_MIN && h != INT_MIN)
		{
			d = h;
			h = INT_MIN;
			d /= obj.h;
			cout << "d is " << d << endl;
		}
		else if (obj.d != DBL_MIN && d != DBL_MIN) d /= obj.d;
		else  if (!obj.str.empty() && !str.empty());
		else if (obj.h != INT_MIN && d != DBL_MIN) d /= obj.h;
		else if (obj.d != DBL_MIN && h != INT_MIN)
		{
			d = h;
			h = INT_MIN;
			d /= obj.d;
		}
		else cout << "Uninitialized local variable" << endl;
	}
	return *this;
}

var& var::operator-(const var &obj)
{

	if ((!obj.str.empty() && str.empty()) || (obj.str.empty() && !str.empty()))
	{
		return *this;
	}
	else
	{
		if (obj.h != INT_MIN && h != INT_MIN) h -= obj.h;
		else if (obj.d != DBL_MIN && d != DBL_MIN) d -= obj.d;
		else  if (!obj.str.empty() && !str.empty());
		else if (obj.h != INT_MIN && d != DBL_MIN) d -= obj.h;
		else if (obj.d != DBL_MIN && h != DBL_MIN)
		{
			d = h;
			h = INT_MIN;
			d -= obj.d;
		}
		else cout << "Uninitialized local variable" << endl;
	}
	return *this;
}


var& var::operator*(const var &obj)
{

	if ((!obj.str.empty() && str.empty()) || (obj.str.empty() && !str.empty()))
	{
		return *this;
	}
	else
	{
		if (obj.h != INT_MIN && h != INT_MIN) h *= obj.h;
		else if (obj.d != DBL_MIN && d != DBL_MIN) d *= obj.d;
		else  if (!obj.str.empty() && !str.empty());
		else if (obj.h != INT_MIN && d != DBL_MIN) d *= obj.h;
		else if (obj.d != DBL_MIN && h != DBL_MIN)
		{
			d = h;
			h = INT_MIN;
			d *= obj.d;
		}
		else cout << "Uninitialized local variable" << endl;
	}
	return *this;
}

var& var::operator=(const var &obj)
{
	this->d = obj.d;
	this->h = obj.h;
	this->str = obj.str;

	return *this;

}

std::ostream& operator<<(std::ostream &os, const var& va)
{
	if (va.h != INT_MIN) os << va.h;
	else if (va.d != DBL_MIN) os << va.d;
	else if (!va.str.empty()) os << va.str;
	return os;
}

std::istream& operator>>(std::istream &is, var& va)
{

	string str;
	is >> str;
	int N = va.TypeDetector(str);

	if (N == BET_INT)
	{
		va.h = atoi(str.c_str());
		va.d = DBL_MIN;
		va.str.clear();
	}
	else if (N == BET_DOUBLE)
	{
		va.d = atof(str.c_str());
		va.h = INT_MIN;
		va.str.clear();
	}
	else
	{
		va.str = str;
		va.d = DBL_MIN;
		va.h = INT_MIN;
	}

	return is;
}