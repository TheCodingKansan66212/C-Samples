/*
@NAME: Hannah Robinow	
@DATE: 13 April 2018
@DESCRIPTION: Use arrays and loops to build a guessing game.
*/
#include <iostream>
#include <iomanip>

using namespace::std;


// Function prototypes
void createTemplate(const char secretWord[], char guessTemplate[]);

void updateTemplate(const char secretWord[], char guessLetter, char guessTemplate[]);

bool matchTemplate(const char secretWord[], const char guessTemplate[]);

//---------------------------------------------------------------------------------------------

const int MAX_SIZE = 15;
int main()
{
	const int NUM_LINES = 25;      // Number of lines on the screen

	char secretWord[MAX_SIZE],   // Secret word to be guessed
		guessTemplate[MAX_SIZE];    // Template showing correct guesses
	char guessLetter;                   // Letter guessed

	int numGuesses;                    // Number of letters guessed
	int j;                                     // Counter


	cout << endl << "Enter the secret word: ";   cin >> secretWord;

	// Scroll secrect word off the screen...to hide it
	for (j = 0; j < NUM_LINES; j++) cout << endl;

	// Create an empty guess template.
	createTemplate(secretWord, guessTemplate);

	// Play the game
	//...keep looping(i.e. guessing until secretWord and guessTemplate are identical)

	numGuesses = 0;
	while (!matchTemplate(secretWord, guessTemplate))
	{
		numGuesses++;
		cout << guessTemplate << endl;

		cout << "Guess a letter: ";   cin >> guessLetter;

		// Place CORRECTLY guessed letter in template
		updateTemplate(secretWord, guessLetter, guessTemplate);
	}

	// Display the secret word and the number of guesses.
	cout << guessTemplate << "=" << secretWord << endl;
	cout << "You guessed the word in " << numGuesses << " guesses" << endl;

	return 0;
}


//--------------------------------------------------------------------
// Insert your function implementations here.
//--------------------------------------------------------------------
void createTemplate(const char secretWord[], char guessTemplate[])
{
	//ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION
	int i;
	for (i = 0; secretWord[i] != '\0'; i++) {
		guessTemplate[i] = '_'; //create initial guessTemplate w/ just underscores.
	}
	guessTemplate[i] = '\0';
}
void updateTemplate(const char secretWord[], char guessLetter,
	char guessTemplate[])
{
	// ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION
	int i;
	for (i = 0; secretWord[i]; i++) {
		if (guessLetter == secretWord[i]) {
			guessTemplate[i] = guessLetter;
		}
	}

}
bool matchTemplate(const char secretWord[], const char guessTemplate[])
{

	// ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION
	for (int i = 0; secretWord[i]; i++) {
		if (secretWord[i] != guessTemplate[i]) {
			return false;  //if match isn't found, loop isn't finished.
		}//end if
	}//end for
	return true;
}

/* TERMINAL OUTPUT

TRIAL 1:

______
Guess a letter: a
______
Guess a letter: b
______
Guess a letter: c
______
Guess a letter: d
______
Guess a letter: e
_e___e
Guess a letter: t
te___e
Guess a letter: m
tem__e
Guess a letter: p
temp_e
Guess a letter: l
temple=temple
You guessed the word in 9 guesses
Press any key to continue . . .

TRIAL 2:
_____
Guess a letter: a
a___a
Guess a letter: c
a___a
Guess a letter: l
al__a
Guess a letter: d
al__a
Guess a letter: p
alp_a
Guess a letter: e
alp_a
Guess a letter: h
alpha=alpha
You guessed the word in 7 guesses
Press any key to continue . . .

TRIAL 3:
_____
Guess a letter: a
__a__
Guess a letter: b
b_a__
Guess a letter: z
b_a__
Guess a letter: r
bra__
Guess a letter: y
bra__
Guess a letter: v
brav_
Guess a letter: x
brav_
Guess a letter: o
bravo=bravo
You guessed the word in 8 guesses
Press any key to continue . . .

*/