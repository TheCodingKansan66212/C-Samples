/*
@NAME: Hannah Robinow
@DATE: 3 April 2018
@CLASS: C++ Algorithms, Professor Orrell
@DESCRIPTION: This program will calculate the sum of two dice for each roll, up to 36,000 times.
*/
#include <iostream> 
using std::cout;   using std::ios;
#include <iomanip> 
using std::setw;  using std::setprecision;  using std::fixed;  using std::showpoint;
#include <cstdlib> 
using std::rand;  using std::srand;
#include <ctime>  using std::time;

int main()
{
	const long ROLLS = 36000;
	const int SIZE = 13;

	// The array "expected" contains counts for the expected number of times each sum occurs in 36000 rolls of the dice 
	// Write the declaration of array "expected" here.
	// Initialize the "expected" array here to contain the expected values.  Use  SIZE for the number of elements 
	// For example ... expected[0] and expected[1] will have the value of 0  since there are no ways for two dice to add up to 0 or 1
	// ... expected[2] will hold 1,    1 + 1 gives 2
	//  ...expected[3] will hold 2,    1 + 2 and 2 + 1 both gives 3
	//  ...expected[4] will hold 3,    1 + 3 and 3 + 1 and 2 + 2 all gives 4
	int expected[SIZE] = {};

	int x;      // first die
	int y;      // second die

	int sum[SIZE] = {};// Write declaration for array sum here. Initialize all  elements to zero. Use SIZE for the number of elements 

				// see textbook for initializing arrays at compile time

	srand(time(0));

	// roll dice 36,000 times
	/* Write a for loop that iterates ROLLS times. Randomly  generate values x die and y die
	and increment the appropriate counter in array sum that  corresponds to the sum of x and y */
	for (int i = 0; i < ROLLS; i++) {
		//get random number for x.
		x = (rand() % 6) + 1;
		//get random number for y.
		y = (rand() % 6) + 1;
		//increment each time you get a particular sum 
		sum[x + y]++;
	}

	cout << setw(10) << "Sum" << setw(10) << "Total" << setw(10)
		<< "Expected" << setw(10) << "Actual\n" << fixed << showpoint;

	// display results of rolling dice
	for (int j = 2; j < SIZE; j++)
		cout << setw(10) << j
		<< setw(10) << sum[j]
		<< setprecision(3) << setw(9) << 100.0 * expected[j] / 36 << "%"
		<< setprecision(3) << setw(9) << 100.0 * sum[j] / 36000
		<< "%\n";

	return 0;               // indicates successful completion
} // end main

/*TERMINAL OUTPUT

TRIAL 1:
Sum     Total  Expected   Actual
2       979    0.000%    2.719%
3      2023    0.000%    5.619%
4      2968    0.000%    8.244%
5      4013    0.000%   11.147%
6      5026    0.000%   13.961%
7      6019    0.000%   16.719%
8      5059    0.000%   14.053%
9      3949    0.000%   10.969%
10      3043    0.000%    8.453%
11      1951    0.000%    5.419%
12       970    0.000%    2.694%
Press any key to continue . . .

TRIAL 2:
Sum     Total  Expected   Actual
2       986    0.000%    2.739%
3      2035    0.000%    5.653%
4      3050    0.000%    8.472%
5      4044    0.000%   11.233%
6      4928    0.000%   13.689%
7      5966    0.000%   16.572%
8      4995    0.000%   13.875%
9      4053    0.000%   11.258%
10      3064    0.000%    8.511%
11      1911    0.000%    5.308%
12       968    0.000%    2.689%
Press any key to continue . . .

TRIAL 3:
Sum     Total  Expected   Actual
2       980    0.000%    2.722%
3      2044    0.000%    5.678%
4      2986    0.000%    8.294%
5      4000    0.000%   11.111%
6      4892    0.000%   13.589%
7      5965    0.000%   16.569%
8      5036    0.000%   13.989%
9      4082    0.000%   11.339%
10      3040    0.000%    8.444%
11      1985    0.000%    5.514%
12       990    0.000%    2.750%
Press any key to continue . . .


*/