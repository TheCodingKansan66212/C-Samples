//   Complete the following program 
//           The program generates 500 numbers between 1 and 6 and stores  them in an array
//           The program loops and counts how many times each number occurs

#include <iostream>
#include <cmath>
using namespace::std;

void generateData(int[], int count);

int countValue(const int[], int howMany, int value);

void main()
{
	int data[1000];
	int howMany = 500;

	generateData(data, 500);     //   call the function to generate 500 numbers between 1 and 6
						//   storing the values in the data array;

	for (int i = 1; i <= 6; i++)
	{
		int valueCount = countValue(data, howMany, i);
		cout << i << " " << valueCount << endl;     // call the countValue function
	}
}

void generateData(int d[], int cnt)
{
	srand(12345);
	int dice;
	for (int i = 0; i < cnt; i++)
	{
		dice = (rand() % 6) + 1;     //  generate a random number between 1 and 6
		d[i] = dice;            // store it in the next position
	}
}//end generateData

int countValue(const int d[], int howMany, int value)
{
	int total = 0;
	for (int i = 0; i < howMany; i++)
	{
		if ( d[i] == value)  //  adjust the total if number in cell i is equal to the parameter "value"
			total++;
	}
	return total;
}//end countValue

/* TERMINAL OUTPUT

TRIAL 1:

1 84
2 79
3 84
4 83
5 78
6 92
Press any key to continue . . .


TRIAL 2: 

1 84
2 79
3 84
4 83
5 78
6 92
Press any key to continue . . .


TRIAL 3: 

1 84
2 79
3 84
4 83
5 78
6 92
Press any key to continue . . .

*/