/*
@NAME: Hannah Robinow
@DATE: 18 April 2018
@DESCRIPTION: Use pointers to manipulate data in a heap.
*/
#include <iostream>
#include <iomanip>

using namespace std;

void printArray(const char *, ostream &, const int *, int howMany);

void main()
{
	int * info;
	int used;
	cout << "How many elements in the array? ";
	cin >> used;
	while (used <= 0)
	{
		cout << "Enter a value of 1 or more" << endl;
		cin >> used;
	}
	// 3 - WRITE THE CODE TO ACQUIRE THE MEMORY FOR THE ARRAY FROM THE HEAP
	int * getSpace = NULL;
	getSpace = new int[used]; //am I allocating memory space == the user input for amt. of integers?

							  // 4 - USING SUBSCRIPTS WRITE THE CODE TO FILL THE ARRAY WITH MULTIPLES OF 3 -
							  // - i.e. cell 0 holds 0, cell 1 holds 3, cell 2 holds 6, etc.
	for (int i = 0; i <= used; i++) {                            // ask tutor if this is most efficient for filling array.
		getSpace[i] = i + 3;
	}
	printArray("Array of data", cout, info, used);

	// 5 - WRITE THE CODE TO RETURN THE MEMORY TO THE HEAP
	delete[] getSpace;
}//ENDMAIN

void printArray(const char * m, ostream & Out, const int * p, int hm)
{
	Out << m << endl;
	for (int i = 0; i < hm; i++)
	{
		Out << p[i] << endl;
	}
}


/*
int range = high - low + 1;
srand(time(0));
for (int i = 0; i < howMany; i++)
{
p[i] = rand() % range + low;
}
*/

