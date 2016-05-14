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
	unsigned int size = strlen(str);
	unsigned int counter = 0;
	char* str1 = str;
	char ch;
	if (index >= size) return ' ';

	while (*str1)
	{
		if (counter == index)
		{
			ch = *str1;
			break;
		}
		*str1++;
		counter++;
	}
	return ch;
}


var& var::operator=(int a)
{
	d = a;
	*str = NULL;
	return *this;
}

var& var::operator=(double a)
{
	d = a;
	*str = NULL;
	return *this;
}

var& var::operator=(char* a)
{
	*str = *a;
	d = DBL_MIN;
	return *this;
}


var& var::operator=(const var &obj)
{
	this->d = obj.d;
	this->str = obj.str;

	return *this;

}


std::ostream& operator<<(std::ostream &os, const var& va)
{
	if (va.d != DBL_MIN) os << va.d;
	else if (strlen(va.str) != 0)
	{
		os << va.str;
	}
	return os;
}

std::istream& operator>>(std::istream &is, var& va)
{

	string str;
	is >> str;
	int N = va.TypeDetector(str);

	if (N == BET_DOUBLE||N==BET_INT)
	{
		va.d = atof(str.c_str());
		va.str = NULL;
	}
	else
	{
		va.str = &str.at(0);

		va.d = DBL_MIN;
	}

	return is;
}

var& var::operator+(const int &obj)
{
	//var obj2 = *this;
	if ( strlen(str) != 0)
	{
			string str1 = str;
			str1 += to_string(obj);
			str = &str1.at(0);
	}
	else
	{
		d += obj;
	}

	return *this;
}

var& var::operator+(const double &obj)
{
	if (strlen(str) != 0)
	{
		string str1 = str;
		str1 += to_string(obj);
		str = &str1.at(0);
	}
	else
	{
		d += obj;
	}

	return *this;
}

var& var::operator+(const var &obj)
{
	var *obj2 = this;
	if (((strlen(obj.str) != 0 && strlen(str)==0)) || ((strlen(obj.str) == 0 && strlen(str) != 0)))
	{
		
		if (obj.d != DBL_MIN)
		{
			string str1 = str;
			str1 += to_string(obj.d);
			obj2->str = &str1.at(0);
		}
		else
		{
			string str1 = str;
			str1 += obj.str;
			obj2->str = &str1.at(0);
		}
		
	}
	else
	{
		 if (obj.d != DBL_MIN && d != DBL_MIN) obj2->d += obj.d;
		 else  if (strlen(obj.str) != 0 && strlen(str) != 0)
		 {
			 string str1 = str;
			 str1 += obj.str;
			 obj2->str = &str1.at(0);
		 }
		else if (obj.d != DBL_MIN)
		{
			obj2->d += obj.d;
		}
		else cout << "Uninitialized local variable" << endl;
	}
		return *obj2;
}

/*
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



*/