#include "vararray.h"

int main() {
	int *a=new int[0];
	int size = 0;
	string input1;
	string input2;
	int value = -1;
	while (true) {
		cout << "enter operation [a/r/q] and number: ";
		cin >> input1;
		if (input1 == "q") {
			return 0;
		} else if (input1 == "a") {
			cin >> input2;
			value = atoi(input2.c_str());
			addNumber(a, value, size);
			output(a, size);
		} else if (input1 == "r") {
			cin >> input2;
			value = atoi(input2.c_str());
			removeNumber(a, value, size);
			output(a, size);
		} else {
			cout << endl << "Please use a r or q" << endl;
		}
		cout << "size = " << size << endl;
	}
}
