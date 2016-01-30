#include <iostream>

using namespace std;

int main() {
	cout << "Input numbers [0 to quit]: ";
	float tmp = 0;
	float total = 0;
	int n = 0;
	cin >> tmp;
	while (tmp != 0) {
		total += tmp;
		cin >> tmp;
		n++;
	}
	if (total == 0) {
		cout << "Nothing to be done, have a great day." << endl;
	} else {
		cout << "Total sum is: " << total << endl;
		cout << "Average is: " << total/n << endl;
	}
}
