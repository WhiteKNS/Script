#include <iostream>
#include "var.h"

using namespace std;

int main()
{
	var a = 10;
	var b = 2.5;
	var c = 12.3;

	cout << "size of var is " << sizeof(a) << endl;
	var str = "Hello, Kitty";
	cout << str << endl;

	var g = a + b + "hello";

	cout << g <<" a "<<a<<endl;

	//var baby = (var)5 + a + b;
	//cout << baby << endl;
	
	return 0;
}