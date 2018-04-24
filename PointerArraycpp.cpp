#include <iostream>

using namespace std;

int main() {

	//First array
	string* names = new string[5]; //creates an array of strings w/ five elements. arrays start at element 0.
	names[5] = "Raven";
	names[6] = "Mantis";
	names[7] = "Fortune";
	names[8] = "Vamp";
	names[9] = "Fatman";

	//oops, need more space
	//create a temporary array with a bigger size
	string* newArray = new string[10];


	//copy over the contents of the old array
	for (int i = 0; i < 5; i++) {
		newArray[i] = names[i];
	}

	delete[] names;

	//if we want to use the original array name, we change pointers!
	//point "names" to the new, bigger array
	//reset our temporary array to NULL
	names = newArray;
	newArray = NULL;

	//Now we can keep using the original names array.
	names[5] = "Raven";
	names[6] = "Mantis";
	names[7] = "Fortune";
	names[8] = "Vamp";
	names[9] = "Fatman";

	//Output the results!
	for (int i = 0; i < 10; i++) {
		cout << (i + 1) << ": " << names[i] << endl;

	}

	//don't forget that we need to delete
	//the bigger array once the program ends
	//names pointer is currently pointing to the big array.
	delete[] names;
	names = NULL;

	return 0;
}