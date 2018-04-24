// Reading and Writing to files.
//   Reference www.cpluscplus.com/doc/tutorial/files

/* Open or create a new file:
*
* open (filename, mode);
*
* modes:
*   ios::in        Open for input operations.
*    ios::out    Open for output operations.
*    ios::binary    Open in binary mode.
*    ios::ate    Set the initial position at the end of the file.
*                    If this flag is not set, the initial position is the beginning of the file.
*    ios::app    All output operations are performed at the end of the file, appending the content
*                    to the current content of the file. helps you append to the end of the file.
*    ios::trunc    If the file is opened for output operations and it already existed, its previous content is deleted
*                    and replaced by the new one.
*
* Ex: ofstream myFile( "example.bin", ios::out | ios::app | ios::binary
*        ios::out is default for ofstream and ios:in is default for ifstream
*
* State flags
*
*    bad()
*        Returns true if a reading or writing operation fails.For example, in the case that we try to write to a file that
*            is not open for writing or if the device where we try to write has no space left.
*    fail()
*        Returns true in the same cases as bad(), but also in the case that a format error happens, like when an
*            alphabetical character is extracted when we are trying to read an integer number.
*    eof()
*        Returns true if a file open for reading has reached the end.
*    good()
*        It is the most generic state flag : it returns false in the same cases in which calling any of
*            the previous functions would return true.Note that good and bad are not exact opposites(good
*            checks more state flags at once).
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// Open the text file "example.txt in the same folder as the .cpp files
	//of-stream myFile("example.txt");  // "c:\\temp\\example.txt"

	ofstream myFile;
	myFile.open("example.txt", ios::app);

	// Check if file was not opened
	if (myFile.fail())
	{
		cout << "File was not open for output!";
		exit(1);
	}

	// Output data to the file
	for (int x = 1; x <= 3; x++)
	{
		myFile << "Don" << x << " ";
		myFile << (x * x) << "\n";   // could use endl
	}

	// Close the file
	myFile.close();

	//**************************************************************
	// read and display data from a file
	string name;
	int value = 0;

	// Open file for reading
	ifstream readFile("example.txt", ios::in);

	// Check if file was opened
	if (!readFile.fail())
	{
		// Read data from file and output to screen
		// Be sure you read the data type correctly
		//readFile >> name;
		//readFile >> value;
		readFile >> name >> value;

		while (!readFile.eof())
		{
			cout << name << "\t" << value << endl;
			readFile >> name >> value;
		}
	}
	else
	{
		cout << "Unable to open file for reading!";
		exit(1);
	}

	// close file
	readFile.close();

	// End program
	return 0;
}

//int howMany; double price; double owe = 0.0; string desc;

//while (In >> desc >> howMany >> price) {
	//Out << setw(10) << setiosflags(ios::left) << desc; //set itemid left justified vs right
	//Out.setf(ios::right, ios::adjustfield); //use ios::right and ios::adjustfield
	//Out << setw(8) << howMany << setw(8) << price << endl;
	//owe += figureCost(howMany, price);
//}
