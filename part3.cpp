// Test program for the displayBox() function.
/*
@NAME: Hannah Robinow
@DATE: 27 March 2018
@DESCRIPTION: This program is going to use a function overloading to return a sum.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace::std;

//function prototype for sum function. include a prototype for each type of function.
int sum(int, int);
int sum(int, int, int);
int sum(int, int, int, int);
int sum(int, int, int, int, int);

int main() {

	int total = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0; //variables that will get passed into the functions

	cout << "Input 5 integers for calculating the sum: " << endl;
	cin >> a >> b >> c >> d >> e;

	total = sum(a, b) + sum(a, b, c) + sum(a, b, c, d) + sum(a, b, c, d, e);

	cout << "The total is: " << total << "." << endl;

	return 0;
}

int sum(int a, int b) { //function that passes two parameters by reference.

	return a + b;

}

int sum(int a, int b, int c) { //function that passes three parameters by reference. 

	return (sum(a, b) + c);

}

int sum(int a, int b, int c, int d) { //function that passes four parameters by reference. 

	return (sum(a, b, c) + d);

}

int sum(int a, int b, int c, int d, int e) { //function that passes five parameters by reference. 

	return (sum(a, b, c, d) + e);

}

/* TERMINAL OUTPUT

TRIAL 1: 
Input 5 integers for calculating the sum:
1 2 3 4 5
The total is: 34.
Press any key to continue . . .

TRIAL 2:
Input 5 integers for calculating the sum:
5 6 7 8 9
The total is: 90.
Press any key to continue . . .

TRIAL 3:
Input 5 integers for calculating the sum:
1 3 5 7 9
The total is: 54.
Press any key to continue . . .

*/