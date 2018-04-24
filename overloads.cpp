//function overloading, SAME function name, different parameters

#include <iostream>

using namespace std;

double larger(double, double); //function declaration. you can leave out the variable names because at this point, all the compiler needs to know is the datatype being passed.
int larger(int, int);
int larger(int, int, int);
int larger(int, int, int, int);
int larger(int, int, int, int, int);

int main() {

	cout << larger(4.3, 5.6) << endl;
	cout << larger(7, 3) << endl;
	cout << larger(3, 6, 1) << endl;
	cout << larger(12, 43, 1, 97) << endl;
	cout << larger(5, 1, 9, 1, 2) << endl;

	return 0;
}

double larger(double a, double b) { //if you pass an integer into a function requiring a double, the program won't run, and will return an error. 
	return a > b ? a : b;
}

int larger(int a, int b) {
	return a > b ? a : b;
} //function will still run despite being overloaded b/c the number of parameters being passed to the functions w/ same name, though they have a different datatype. 

int larger(int a, int b, int c) {
	int d = larger(a, b);
	return c > d ? c : d; //calls a pre-existing function; returns the largest of a or b if either one is larger than the variable c being passed in.
} //the function called "larger" now takes three parameters. 

int larger(int a, int b, int c, int d) {
	return larger(a, larger(b, c, d));
	//return larger(larger(a, b), larger(c, d)); --> both of these function calls are alternate ways to accomplish the call used in this pass-by-value function
	//return larger(a, b, larger(c, d));

}//the return statement returns the largest of b, c, and d, then compares the returned value to a, and returns whichever is the largest between the returned result and a. 
//akin to putting the variables through a playoff bracket ;-)

int larger(int a, int b, int c, int d, int e) { //overrides the function by taking different parameters
	return larger(larger(a, b, c), larger(d, e)); //each nested function call finds the largest between a/b/c respectively, or between d/e
}//then, it returns the largest of the results from the two previous function calls
