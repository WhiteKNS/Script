#include <iostream>
#include "var.h"

using namespace std;

int main()
{
	var a = 10;
	var b = 2.5;
	var c = 12.3;
	var str = " Hello, Kitty";
	var g = a / b; //'a' store the result too...
	cout << "/ " << g << endl; //true;

	var result = a + b + c; //false because var 'a' store the result of (a+b). But how to do that?
	
	result = result + 5; //false;
	cout <<"result "<< result << endl;//false;
	return 0;
}