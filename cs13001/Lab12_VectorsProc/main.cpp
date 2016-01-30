#include "compute.h"

int main() {
	vector<int> v;
	string command;
	int value;
	while (true) {
		cout << "enter operation [a/r/q] and number: ";
		cin >> command;
		if (command == "q") {
			return 0;
		} else if (command == "a") {
			cin >> value;
			add(v, value);
			print(v);
		} else if (command == "r") {
			cin >> value;
			remove(v, value);
			print(v);
		}
	}
}