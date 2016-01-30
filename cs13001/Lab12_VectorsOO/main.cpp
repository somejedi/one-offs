#include "vectorsoo.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	vectorsoo v;
	string command;
	int value;
	while (true) {
		cout << "enter operation [a/r/q] and number: ";
		cin >> command;
		if (command == "q") {
			return 0;
		} else if (command == "a") {
			cin >> value;
			v.addNumber(value);
			v.output();
		} else if (command == "r") {
			cin >> value;
			v.removeNumber(value);
			v.output();
		}
	}
}