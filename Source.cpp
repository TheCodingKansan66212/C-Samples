#include <iostream>
#include <fstream> // For reading and writing files.

using namespace std;

int main()
{
	ifstream iFile;//For reading from file
	ofstream oFile;//For writing to file

	char ch;

	iFile.open("message.txt");//Opens your file in reading mode.
	oFile.open("upper.txt", ios::app);//Opens the upper.txt file in appending mode.
	cout << "Message in message.txt:" << endl;

	//Runs loop until the control reaches end of the message.txt file.
	while (!iFile.eof())
	{
		ch = iFile.get();//Read charcter by character.
		cout << ch;// Prints to console.

				   //Checks if the character is lower or upper case.
		if (islower(ch))
		{
			ch = toupper(ch);//Changes lower case to upper case.
			return ch;
		}

		oFile << ch;

	}// End of while loop.

	iFile.close();
	//Open the upper.txt in reading mode.
	iFile.open("upper.txt");
	cout << "Message in upper.txt:" << endl;

	//Runs loop until the control reaches end of the upper.txt file.
	while (!iFile.eof())

	{
		//Read character by character.
		ch = iFile.get();
		//Prints the upper case letters.
		cout << ch;

	}//End of while loop.

	 //Close the file stream.
	iFile.close();

	system("pause");

	return 0;

}// End of main.
