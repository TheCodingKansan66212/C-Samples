#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	char newChar;
	
	fstream newFile;
	fstream upperFile;

	//opening the file. 
	newFile.open("message.txt", ios::out);
	upperFile.open("upper.txt", ios::out);

	if (!newFile) {
		cout << "Unable to open file ";
		exit(1); //closes application with an error code.
	}

	cout << "File created successfully. " << endl;

	//check for uppercase characters.
	while (!newFile.eof()) {
		newChar = newFile.get(); // parse each character.

						 //check for case.
		if (islower(newChar)) {
			newChar = toupper(newChar); //change cases.
			upperFile << newChar;
		}
		else if (!islower(newChar)) {
			upperFile << newChar;
		}
	}

	upperFile.close();
	newFile.close();

	upperFile.open("upper.txt", ios::in); //open file in read mode

	if (!upperFile) {
		cout << "File not found. " << endl;
		exit(1);
	}

	//read until end of file isn't found.
	cout << "The new file contains: " << endl;

	char displayChar;
	while (!upperFile.eof()) {
		upperFile >> displayChar;
		cout << displayChar;
	}

	upperFile.close();

}

/*
TEST OUTPUT: 

File created successfully.
The new file contains:
  Press any key to continue . . .

*/
