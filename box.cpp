// Test program for the displayBox() function.
/*
@NAME: Hannah Robinow
@DATE: 27 March 2018
@DESCRIPTION: This program is going to use a function to build a box using pass-by-reference variables.
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace::std;

//  Function prototypes

void displayBox(int length);
void displayBox(int length, char fillChar);
void displayBox(int width, int height);
void displayBox(int width, int height, char FillChar);

//--------------------------------------------------------------------

int main()
{
	int boxLength,   // Input box dimensions
		boxWidth,
		boxHeight;

	char boxFill;    // Input fill character

					 // Test the displayBox(length) and displayBox(length,fillChar) functions.
	cout << endl << "Enter the length of a side: ";    cin >> boxLength;
	displayBox(boxLength);
	cout << endl << "Enter the fill character: ";    cin >> boxFill;
	displayBox(boxLength, boxFill);

	// Test the displayBox(width,height) and displayBox(width,height,fillChar) functions.
	cout << endl << "Enter the width and height of the box: ";    cin >> boxWidth >> boxHeight;
	displayBox(boxWidth, boxHeight);
	cout << endl << "Enter the fill character: ";    cin >> boxFill;
	displayBox(boxWidth, boxHeight, boxFill);

	return 0;
}

//--------------------------------------------------------------------
void displayBox(int length)
{
	//  call the 2 argument function, int and char
	displayBox(length, ' ');
}


void displayBox(int length, char fillChar)
{
	//  call the 3 argument function
	displayBox(length, length, fillChar);
}


void displayBox(int width, int height)
{
	// call the 3 argument function
	displayBox(width, height, ' ');
}

void displayBox(int width, int height, char FillChar)
{
	// using nested loops, write this function
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
				cout << 'X';
			}
			else {
				cout << FillChar;
			}//end else
		}//end for
		cout << endl << endl;
	}
}


/*TERMINAL OUTPUT
 TRIAL 1:

 Enter the length of a side: 8
 XXXXXXXX

 X      X

 X      X

 X      X

 X      X

 X      X

 X      X

 XXXXXXXX


 Enter the fill character: O
 XXXXXXXX

 XOOOOOOX

 XOOOOOOX

 XOOOOOOX

 XOOOOOOX

 XOOOOOOX

 XOOOOOOX

 XXXXXXXX


 Enter the width and height of the box: 6


 TRIAL 2:

 Enter the length of a side: 4
 XXXX

 X  X

 X  X

 XXXX


 Enter the fill character: T
 XXXX

 XTTX

 XTTX

 XXXX


 Enter the width and height of the box:

 TRIAL 3:

 Enter the length of a side: 5
 XXXXX

 X   X

 X   X

 X   X

 XXXXX


 Enter the fill character: E
 XXXXX

 XEEEX

 XEEEX

 XEEEX

 XXXXX


 Enter the width and height of the box:
*/