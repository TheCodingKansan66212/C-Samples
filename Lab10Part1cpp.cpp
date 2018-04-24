/*
@NAME: Hannah Robinow
@DATE: 16 April 2018
@DESCRIPTION: Find the largest element in an array.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int largeArray(const int[], int, int);
int largePointer(const int *, int, int);
void fillArray(int *, int howMany);
void printArray(const char *, ostream &, const int *, int howMany);

const int low = 50; const int high = 90;

void main()
{
	const int MAX_SIZE = 40;
	int info[MAX_SIZE];
	int used;
	cout << "How many elements in the array? ";
	cin >> used;
	while (used <= 0 || used > MAX_SIZE)
	{
		cout << "Enter a value between 1 and " << MAX_SIZE << "How many elements in the array? ";
		cin >> used;
	}
	fillArray(info, used);
	printArray("Array of data", cout, info, used);

	cout << "The largest element using subscripts is " << largeArray(info, used) << endl;
	cout << "The largest element using pointers is " << largePointer(info, used) << endl;
}

//ENDMAIN

void printArray(const char * m, ostream & Out, const int * p, int hm)
{
	Out << m << endl;
	for (int i = 0; i < hm; i++)
	{
		Out << p[i] << endl;
	}
}
void fillArray(int * p, int howMany) // as parameters, pointers and arrays are one and the same
{
	int range = high - low + 1;
	srand(time(0));
	for (int i = 0; i < howMany; i++)
	{
		p[i] = rand() % range + low;
	}
}
int largeArray(const int data[], int howMany, int used) // use subscripts
{
	int largest = 0;
	// 1 - WRITE THE CODE TO FIND THE LARGEST NUMBER - USE SUBSCRIPTS TO ACCESS THE ELEMENTS 
	for (int i = 0; i <= used; i++) {
		if (data[i] > largest) {
			largest = data[i];
		}
		else if (data[i]) //do I need to include a contingency plan in case I don't find the largest in the array?
	}
	return largest;
}
int largePointer(const int * data, int howMany, int used) // use pointers
{
	int largest = 0;
	// 2 - WRITE THE CODE TO FIND THE LARGEST NUMBER - USE POINTERS TO ACCESS THE ELEMENTS 
	for (int j = 0; j <= used; j++) {
		if (data[j] > largest) {
			largest = data[j]; //is subscripting in a pointer any different than in a regular array? am I accessing the right data?

		}
	}
	return largest;
}
