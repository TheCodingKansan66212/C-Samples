#include <fstream>     //disk file access
#include <iomanip>
#include <iostream>   // cin and cout access
#include <string>
using namespace::std;

double figureCost(int, double);
void prepareOutput(ostream &);

int main()
{
	ofstream Out;
	//	Open output file
	//Out.open("c:\temp\StudentsStuff\itemsOut.out");
	Out.open("itemsOut.out");
	if (!Out)
	{
		cout << "Could not open output file\n";   return;
	}

	prepareOutput(Out);

	ifstream In;
	//In.open("c:\\temp\\StudentsStuff\\myItems.txt");
	In.open("myItems.txt");

	if (!In)
	{
		cout << "File not opened\n";   return;
	}

	cout << "Ready to read data from the file ---" << endl;

	int howMany;   double price;   double owe = 0.0;   string desc;

	// if the actual data in the file is not in exact sets of 3, the results will be unpredictable

	while (In >> desc >> howMany >> price)
	{
		//Out << setw(10) << setiosflags(ios::left) << desc;    //set itemid left justified vs right
		//Out.setf(ios::right, ios::adjustfield);               //use ios::right and ios::adjustfield
		//Out << setw(8) << howMany << setw(8) << price
			//<< endl;
		Out << setw(10) << left << desc; //this code is much easier to read and work with than the code in lines 40-43 above.
		Out << setw(8) << right << howMany << setw(8) << right << price << endl; //st(8) sets a width of 8 characters. 
		owe += figureCost(howMany, price); //this is a pass-by value function
	}

	In.close();
	Out << "You owe " << owe << endl;
	Out.close();
}  // end of main()

double figureCost(int qty, double p) //price needs to be a double, because it's double-digit return
{
	double answer;
	answer = (double)qty * p; //the (double) casts answer as such when it returns, since you're multiplying an int by a double.
	return answer;
}

void prepareOutput(ostream & w) //the "&" symbol indicates a pass-by-reference function. When the function gets called in Main(), the variable Out gets passed to it.
								// in the function header, the variable "w" is an address for the variable. This means that you no longer have to use the same name for a variable passed
								// to the function, unlike pass-by-value functions.
{
	w << setiosflags(ios::showpoint | ios::fixed)
		<< setprecision(2) << setfill('#');                   // also can setfill any other char
}                                                             // i.e. setfill('#')

															  /*
															  Ready to read data from the file ---
															  in the file c:\temp\StudentsStuff\itemsOut.out
															  the output is :

															  coke       3    2.50
															  milk       2    3.80
															  juice      2    2.80

															  You owe 20.70
															  */
															  //----------------------------------------------------------------------------

															  /*------NOTE: in the path of   c:\temp\StudentsStuff\myItems.txt
															  We have the data as follows:

															  coke   3    2.5
															  milk   2    3.8
															  juice  2    2.8

															  */