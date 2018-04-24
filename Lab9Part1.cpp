/*
@NAME: Hannah Robinow
@DATE: 13 April 2018
@DESCRIPTION: Use loops to turn a single word into plurals.
*/
#include <iostream>
#include <iomanip>

using namespace::std;

void addLetterS(const char orig[], char plural[]);

int main() {

	char word[10];
	char school[10];

	cout << "Enter the word, \"school\": " << endl;
	cin >> school;

	addLetterS(school, word); // copy word into school and add an 's' to the end
	cout << word << endl;      // will output the contents of word i.e. "schools"


	return 0;
}


void addLetterS(const char orig[], char plural[]) {
	//ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION
	int i;
	for (i = 0; orig[i] != '\0'; i++) {
		plural[i] = orig[i]; //create initial guessTemplate w/ just underscores.
	}
	plural[i] = 's';
	plural[i + 1] = '\0';

	
}

/*
TERMINAL OUTPUT: 

TRIAL 1:

Enter the word, "school":
schoool
schoools
Press any key to continue . . .

TRIAL 2: 

Enter the word, "school":
school
schools
Press any key to continue . . .

TRIAL 3:

Enter the word, "school":
schooool
schooools
Press any key to continue . . .


*/