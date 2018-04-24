#include<iostream>
#include<cstdlib>


using namespace std;

using std::cin; using std::cout; using std::endl;

//DECLARE the owedTax prototype of type double with double parameter
double owedTax(double);


int main() {

	int income, owed;

	//Prompt user for an income amount
	cout << "Enter your income amount: " << endl;
	cin >> income; //Input the income

	if (income > 0) {
		
		owed = owedTax(income);
		cout << owed << endl;
	}
	else
		cout << "Invalid income." << endl;


}

double owedTax(double i) {   //function header 
	double tax;

	if (i > 336550) {
		tax = (97653 + .35*(i - 336550));
	}
	else if (i > 154800 && i <= 336550) {
		tax = (37675.5 + .33*(i - 154800));
	}
	else if (i > 74200 && i <= 154800) {
		tax = (15107.5 + .28*(i - 74200));
	}
	else if (i > 30650 && i <= 74200) {
		tax = (4220 + .25*(i - 30650));
	}
	else if (i > 7550 && i <= 30650) {
		tax = (755 + .15*(i - 7550));
	}
	else if (i > 0 && i <= 7550) {
		tax = (0.1*i);
	}

	return tax;
}


