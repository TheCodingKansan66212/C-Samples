// Test program for the displayBox() function.
/*
@NAME: Hannah Robinow
@DATE: 27 March 2018
@DESCRIPTION: This program is going to use a function to swap integers using pass-by-reference and function overloading in order to return\sample test scores.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace::std;


//function prototype
bool figureGrade(int, char &);

int main() {
	int score;
	char grade;

	cout << "Enter the student's score: " << endl; //get user input to calculate their grades.
	cin >> score;


	if (figureGrade(score, grade)) {
		cout << "The score is: " << score << "." << endl;
		cout << "The grade is: " << grade << "." << endl;
	}

	else
		cout << "Invalid score." << endl;

	return 0;
}

bool figureGrade(int score, char &grade) {

	if (score > 0 && score <= 100) {
		if (score >= 0 && score <= 59) {
			grade = 'F';
		}
		else if (score >= 60 && score <= 69) {
			grade = 'D';
		}
		else if (score >= 70 && score <= 79) {
			grade = 'C';
		}
		else if (score >= 80 && score <= 89) {
			grade = 'B';
		}
		else if (score >= 90 && score <= 100) {
			grade = 'A';
		}
	}//end if
	else
		return false;
}//end figureGrade



/* TERMINAL OUTPUT:

TRIAL 1: 
Enter the student's score:
85
The score is: 85.
The grade is: B.
Press any key to continue . . .


TRIAL 2:
Enter the student's score:
75
The score is: 75.
The grade is: C.
Press any key to continue . . .


TRIAL 3: 
Enter the student's score:
70
The score is: 70.
The grade is: C.
Press any key to continue . . .


*/