#include <iostream>
#include "var.h"

using namespace std;

int main()
{
	var a = 5;
	var b = 5.7;
	var c = 12.3;
	cout << "b "<<b << endl;
	var str = " Hello, Kitty";
	var str2 = str + "Hi!";
	var result = a + b+c;
	result = result + str2;
	cout <<"result "<< result << endl;
	return 0;
}