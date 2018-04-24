/*
@NAME: Hannah Robinow
@DATE: 13 April 2018
@DESCRIPTION: Reverse a word using char arrays.
*/
#include <iostream>
#include <iomanip>

using namespace::std;
const int MAX_SIZE = 15;     // Max word size of word, 14 chars plus  '\0'
void reverse(char word[]);    // function prototype

void main()
{

	char word[MAX_SIZE];
	cout << endl << "Enter a word : ";  cin >> word;
	cout << "You entered the word " << word << endl;
	reverse(word);
	cout << "The word in reverse order is " << word << endl;

}//END MAIN

void reverse(char word[])
{
	// you cannot have any local array variables inside this function
	int right;
	//find end of string
	for (right = 0; word[right] != '\0'; right++) {
	}

	int left = 0;
	right--;
	char temp;

	while (!(left >= right)) {
		temp = word[left];
		word[left++] = word[right];
		word[right--] = temp;
	}
}

/*TERMINAL OUTPUT

TRIAL 1:

Enter a word : food
You entered the word food
The word in reverse order is doof
Press any key to continue . . .


TRIAL 2:

Enter a word : THOUGHT
You entered the word THOUGHT
The word in reverse order is THGUOHT
Press any key to continue . . .

TRIAL 3:


Enter a word : together
You entered the word together
The word in reverse order is rehtegot
Press any key to continue . . .



*/