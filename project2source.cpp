// Project #2
//   complete the following program
//   test the program
//   first letting the computer generate the input
//   second letting user input only two sets of data
#include<iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

const bool KEYBOARD = false;
ofstream Out("con");

int    getNumberOfSales();
int    getItemNumber(void);
double getPrice(int itemNumber);
bool   isTaxable(int);
int    getQuantity(int itemNumber);
double getCost(int itemNumber, int count, double price);
double getTax(double sales);
void   printLine(ostream & w, int iNumber, int qty, double price, double cost, bool taxable);
void   printTotal(ostream & w, int loopCount, double grandTotal, double taxDue);
void   headings(ostream & w);
void   startRandom(void);
void   prepareOutput(ostream & w);

void main()
{
	int differentItems,       // Number of items to purchase
		iNumber,    // Item number code
		qty;        // Number of a particular item purchased
	double price,             // Price of a particular item
		cost,              // The cost of the item purchase = price * qty
		taxableTotal = 0,      // Total of all taxable purchases
		nonTaxableTotal = 0,   // Total of all nontaxable purchases
		taxDue,            // Tax due on the taxable total
		grandTotal;        // Sum of taxableTotal, nonTaxableTotal
	bool   taxable = true;                   // Flag to indicate if the item is taxable
	//  Initialize ONLY those TOTALS that need an initial value

	prepareOutput(Out);
	if (!KEYBOARD) startRandom();
	headings(Out); // for computer generated
	differentItems = getNumberOfSales();
	for (int i = 0; i < differentItems; i++)
	{
		iNumber = getItemNumber();
		qty = getQuantity(iNumber);
		price = getPrice(iNumber);
		cost = getCost(iNumber, qty, price);
		taxable = isTaxable(iNumber);
		// headings(Out);   // for keyboard input
		printLine(Out, iNumber, qty, price, cost, taxable);
		//  accumulate
		if (taxable) {
			taxableTotal = getCost(iNumber, qty, price);
		}//end if
		else {
			nonTaxableTotal = getCost(iNumber, qty, price);
		}
		//   ******* -  taxable total
		//   ********  -  nontaxable total
		grandTotal = taxableTotal + nonTaxableTotal;

	}  // ENDFOR
	taxDue = getTax(taxableTotal);
	printTotal(Out, differentItems, grandTotal, taxDue);

	cin.ignore();
	cin.get();
}  //ENDMAIN


void startRandom(void)
{
	int seed;
	cout << "Enter seed value for random number generator: ";
	cin >> seed;
	srand(seed);
}
int getItemNumber(void)
{                             //  item number should be a 4-digit integer
	int num;
	if (KEYBOARD)
	{
		cout << "Enter a 4-digit item number: ";
		cin >> num;
	}
	else
		num = rand() % 9000 + 1000;
	return num;
}
double getPrice(int num)
{
	double price;
	if (KEYBOARD)
	{
		cout << "Enter price for item(MUST BE BETWEEN .10 AND 10.09) " << num << " : ";
		cin >> price;
	}
	else
		price = double(rand() % 1000 + 10) / 100;
	return price;
}

/*{
	double price;
	if (KEYBOARD) {

		cout << "Enter a price: " << endl;
		cin >> price;


		if (price >= 0.1 || price <= 10.09)  //  price should be between .10 and 10.09
		{
			
		}//END IF2
	}

	else
	{
		price = double(rand() % 1000 + 10) / 100;//end if1
	}

	return price;
		
}//end getPrice*/
bool isTaxable(int itemNumber)
{
	char input;

	//  ask the user     
	//       OR
	//   computer will make NOT taxable if itemNumer is divisible by 5

	if (KEYBOARD)
	{
		cout << "Is the item taxable? Y/N: " << endl;
		while (true)
		{
			cin >> input;

			if (input == 'Y') {
				return true;
			}
			else if (input == 'N') {
				return false;
			}

			else
			{
				cout << "Invalid Input";
			}
		}
	}

	else {
		if (itemNumber % 5 == 0) {
			return false;
		}
		else
			return true;
	}
}


int getQuantity(int num)
{
	//  ask the user
	//       OR
	//   computer will make a choice between 1 and 8

	
	if (KEYBOARD) {
		cout << "Enter a the quantity of items: " << endl;
		cin >> num;
		
	}//end if
	else {
		
		num = int(rand() % 8 + 1);//end if1
	}
	return num;

}//end getQuantity
int getNumberOfSales()
{
	int salesAmt = 0;
	//  ask the user
	//       OR
	//   computer will make a choice between 1 and 15
	if (KEYBOARD) {
		cout << "Enter the number of sales: " << endl;
		cin >> salesAmt;
	}
	else {
		salesAmt = int(rand() % 15 + 1);
	}
	return salesAmt;
}//end getNumberOfSales
double getCost(int itemNumber, int count, double price){
	
	return price * count;
}
double getTax(double sales)
{  //   define a const for the sales tax rate 
	const double salesTax = 0.0725;

	return sales * salesTax;
}
void printLine(ostream & w, int iNumber, int qty, double price, double cost, bool taxable){
	//w << "***Detail line*******" << endl;  // print a "*" for the item which is
										   // not taxable
	// ternary operator; true/false conditions--> true is on the left of the semi-colon, false is on the right

	(taxable) ? (w << setw(10) << iNumber << setw(10) << qty << setw(10) << price << setw(10) << cost << endl) : (w << setw(10) << iNumber << setw(10) << qty << setw(10) << price << setw(10) << cost << "*" << endl);
}//end printLine
void printTotal(ostream & w, int loopCount, double grandTotal, double taxDue)
{
	w << "Purchase: " << grandTotal << endl;
	w << "Tax: " << taxDue << endl;
	w << "Amount: " << grandTotal + taxDue << endl;

	w << loopCount << " kinds of different items purchased. " << endl;

	w << endl << " * indicates item was not taxable ." << endl;
}

void headings(ostream & w)
{
	w << setw(10) << "item #" << setw(10) << "quantity" << setw(10) << "price" << setw(10) << "cost" << endl << endl;
}

void prepareOutput(ostream & w)
{
	w << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);
}



/* TERMINAL OUTPUT RESULTS:


TRIAL 1: 

Enter seed value for random number generator: 7750
item #  quantity     price      cost

3613         8      4.40     35.20
8655         2      6.22     12.44*
4361         4      7.69     30.76
7460         7      1.91     13.37*
5124         5      5.67     28.35
1967         2      5.37     10.74
1722         5      7.53     37.65
1396         3      8.45     25.35
1555         8      6.76     54.08*
7401         7      2.65     18.55
4125         4      9.06     36.24*
2800         5      4.22     21.10*
Purchase: 39.65
Tax: 1.34
Amount: 40.99
12 kinds of different items purchased.

* indicates item was not taxable .

TRIAL 2: 

Enter seed value for random number generator: 7000
item #  quantity     price      cost

3236         7      1.23      8.61
5972         3      8.12     24.36
4361         7      5.32     37.24
2086         4      4.10     16.40
5451         3      8.95     26.85
8024         4      7.54     30.16
2171         8      9.22     73.76
6700         7      1.26      8.82*
Purchase: 82.58
Tax: 5.35
Amount: 87.93
8 kinds of different items purchased.

* indicates item was not taxable .


TRIAL 3: 

Enter seed value for random number generator: 8000
item #  quantity     price      cost

3738         3      7.25     21.75
7626         5      3.03     15.15
2438         5      8.48     42.40
3252         3      1.18      3.54
Purchase: 3.54
Tax: 0.26
Amount: 3.80
4 kinds of different items purchased.

* indicates item was not taxable .


*/