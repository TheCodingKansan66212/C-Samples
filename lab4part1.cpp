// Reverse the digits of a number...123 becomes 321 and 721 becomes 127
#include<iostream>
#include<cstdlib>

using namespace std;

using std::cin; using std::cout; using std::endl;

// Replace this with  prototype definition  for the function
int reverseDigits(int);
int main()
{
	int number;
	int reverse = 0;
	cout << "Enter a number between 1 and 9999: "; cin >> number;
	cout << "The number with its digits reversed is: ";


	reverse = reverseDigits(number);  //insert calling statement to FUNCTION
	cout << "Reverse is = " << reverse << endl;
	return 0;                                // 0 indicates successful termination
} // end main
  //-----------------------------------------------------------------------------------------------------------
  // reverseDigits returns number obtained by reversing digits of n
  // Replace this with FUNCTION HEADER
int reverseDigits(int n)
{
	int reverse = 0;
	int remainder = 0;

	//n, below, is reduced step by step until it becomes 0
	cout << "n = " << n << endl;
	while (n != 0)                 //loop until false
	{
		remainder = n % 10; 	// get the right digit of the number n
		reverse = reverse * 10 + remainder;        // move the new number one digit left and append the digit from above
		n /= 10;                                                 // n is decreased 10 fold

	} // ENDWHILE
	return reverse;                                             // return reversed number
} // ENDFUNCTION
