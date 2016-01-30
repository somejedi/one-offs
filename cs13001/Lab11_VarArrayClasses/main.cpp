#include "vararray.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	varArray va;
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
			va.addNumber(value);
			va.output();
		} else if (input1 == "r") {
			cin >> input2;
			value = atoi(input2.c_str());
			va.removeNumber(value);
			va.output();
		} else {
			cout << endl << "Please use a r or q" << endl;
		}
	}
}
