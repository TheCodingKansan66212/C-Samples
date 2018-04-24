#include<iostream>
#include <iomanip>
#include <fstream>


using namespace std;

//function headers
void printArray(ostream & out, const int grades[], int size);

double calcAverage(const int arr[], int students);

void saveToFile(const int arr[], int size);
int main() {

	int grades[] = { 80, 90, 60, 70, 97 };

	//int grades[5];
	//grades [0] = 80;
	//grades[1] = 90;

	//for(int i = 0; i < 5; i++)
	//{
	//    cout << "Enter a grade: ";
	//    cin >> grades[i];
	//}

	int arraySize = 5;

	printArray(cout, grades, arraySize);

	cout << "The average grade was: " << calcAverage(grades, arraySize) << endl;

	saveToFile(grades, arraySize);

	return 0;
}

void printArray(ostream & out, const int grades[], int size) { //pass output stream by reference into the function; the array gets passed int o
	out << "Element " << "Grades" << endl;
	for (int i = 0; i < size; i++) {
		out << setw(7) << i << setw(5) << grades[i] << endl; //in first column, the first element is displayed w/ a width of 7; second one is a width of 5.
	}
}

double calcAverage(const int arr[], int students) { //pass in the grades array, but the function shouldn't change the values in the array. So, it's going to be pass-by-reference.
	double avg;
	int sum = 0;
	for (int i = 0; i < students; i++) { //students is the theta in the array; it's the number being manipulated.
		sum += arr[i];
	}
	avg = static_cast<double>(sum) / students;
	return avg;
}

void saveToFile(const int arr[], int size) { //this is going to save output to a file.
	ofstream outFile; //at the top of the file, you declare the filestream library.

	outFile.open("Scores.txt");

	//check if the file successfully opened.
	if (outFile.fail()) {
		cout << "Could not open Scores.txt!\n";
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		outFile << arr[i] << ' ';
	}

	outFile.close();

}