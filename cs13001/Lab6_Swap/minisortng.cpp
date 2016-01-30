//demostrates call-by-reference
//bryan zinser
//2/16/2015
#include "swap.h"

int main(){

	// inputs the numbers
	cout << "Enter three numbers: ";
	int one, two, three;
	cin >> one >> two >> three;

	// orders one and two
	if (one > two){
		swap(one, two);
	}

	// orders one and three
	if (one > three){
		swap(one, three);
	}

	// orders two and three
	if (two > three){
		swap(two, three);
	}


	// outputs the sorted numbers
	cout << "The sorted numbers are: ";
	cout << one << " " << two << " " << three << endl;
}
