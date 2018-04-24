// Test program for the displayBox() function.
/*
@NAME: Hannah Robinow
@DATE: 27 March 2018
@DESCRIPTION: This program is going to use a function to do math using pass-by-reference.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace::std;


bool compute(int one, int two, int &sum, int &product, int &quotient);

int main() {
	int one;
	int two;
	int product, quotient, sum; //variables that will get passed by ref into the compute function. 

	cout << "Enter two digits to use: " << endl; //get numbers from user input.
	cin >> one >> two;

	compute(one, two, sum, product, quotient); //variables for the function call in Main.
	
	cout << "The sum is: " << sum << "." << endl; //should I use the returnSum variable instead? 

	cout << "The product is: " << product << "." << endl;

	cout << "The quotient is: " << quotient << "." << endl;


	return 0;
}


bool compute(int one, int two, int &sum, int &product, int &quotient) {
	
	sum = one + two;
	product = one * two;

	if (two != 0) //check if two is greater than 0; prevent divide-by-zero error.
	{
		quotient = one / two;
		return true;
	}
	else
		return false;

}

/*TERMINAL OUTPUT

TRIAL 1:
Enter two digits to use:
4 5
The sum is: 9.
The product is: 20.
The quotient is: 0.
Press any key to continue . . .

TRIAL 2:
Enter two digits to use:
6 5
The sum is: 11.
The product is: 30.
The quotient is: 1.
Press any key to continue . . .

TRIAL 3:
Enter two digits to use:
7
8
The sum is: 15.
The product is: 56.
The quotient is: 0.
Press any key to continue . . .

*/