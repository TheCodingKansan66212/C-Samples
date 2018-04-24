// Test program for the displayBox() function.
/*
@NAME: Hannah Robinow
@DATE: 27 March 2018
@DESCRIPTION: This program is going to use a function to swap integers using pass-by-reference and function overloading in order to return a grid and sample test scores.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace::std;

int swap(int &, int &); //function prototype--> how do i not overload it, and how do i match the argument list in Main()?

int main() {

	int first = 0, second = 0;

	cout << "Enter two digits: " << endl;
	cin >> first >> second;

	swap(first, second);

	cout << "The swapped digits are: " << first << ", " << second << "." << endl;
	return 0;
}

int swap(int &a, int &b) {
	int temp = 0;

	temp = a;
	a = b;
	b = temp;

	return 0;
}
 /*TERMINAL OUTPUT

 TRIAL 1:
 Enter two digits:
 1 2
 The swapped digits are: 2, 1.
 Press any key to continue . . .

 TRIAL 2:
 Enter two digits:
 5 6
 The swapped digits are: 6, 5.
 Press any key to continue . . .

 TRIAL 3:
 Enter two digits:
 8 9
 The swapped digits are: 9, 8.
 Press any key to continue . . .
 */