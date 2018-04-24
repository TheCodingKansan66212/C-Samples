#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;



int main() {

	int sum = 0;
	int x;
	int num = 0, count = 0;
	int getNumOne = 0, getNumTwo = 0;
	ifstream inFile;
	ofstream outFile;

	outFile.open("number.txt", ios::app); //needs correct path for the .txt file
	inFile.open("number.txt", ios::app); //open the file for input

	if (outFile.fail()){
		cout << "Unable to open file." << endl;
		exit(1);
	}

	if (!inFile) {
		cout << "Unable to open file ";
		exit(1); //closes application with an error code.
	}


	//append new numbers to the end of the file. User enters the two numbers 224, and 543.
	cout << "Input the numbers 224, and 543: " << endl;
	outFile << ' ' << 224 << ' ' << 543 << endl;
	//outFile.close();

	//read input from the file, get the sum of the integers.
	while (inFile >> x) {
		sum = sum + x;
		count++;
		cout << num;
		cout << sum; 

		inFile >> num;
		count++;
		cout << num;

		cout << "The sum of the integers in the file is: " << sum << "." << endl;

	}
	cout << "The sum of the integers in the file is: " << sum << "." << endl;

	 //count the numbers in the file.              //used the !inFile.eof() method, but it wasn't the best tool for writing a while loop condition.
		//while (inFile >> x) {             
			//inFile >> num;
			//count++;
			//cout << num;


		//}
	cout << "There are " << count << " numbers in the numbers.txt file." << endl;

	//append new numbers to the end of the file. User enters the two numbers 224, and 543.
	//cout << "Input the numbers 224, and 543: " << endl;
	//outFile << ' ' << 224 << ' ' << 543 << endl;
	outFile.close();

	inFile.close();

	cin.get(); 
	return 0; 
}



/*
Test Output


Input the numbers 224, and 543:
01282The sum of the integers in the file is: 12.
824624The sum of the integers in the file is: 46.
247947The sum of the integers in the file is: 79.
4710088The sum of the integers in the file is: 100.
8822321224The sum of the integers in the file is: 223.
21224766224The sum of the integers in the file is: 766.
2241309224The sum of the integers in the file is: 1309.
2241852224The sum of the integers in the file is: 1852.
2242395224The sum of the integers in the file is: 2395.
2242938224The sum of the integers in the file is: 2938.
2243481224The sum of the integers in the file is: 3481.
2244024224The sum of the integers in the file is: 4024.
2244567224The sum of the integers in the file is: 4567.
2245110224The sum of the integers in the file is: 5110.
2245653224The sum of the integers in the file is: 5653.
2246196224The sum of the integers in the file is: 6196.
The sum of the integers in the file is: 6196.
There are 32 numbers in the numbers.txt file.

*/