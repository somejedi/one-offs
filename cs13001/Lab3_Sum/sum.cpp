// Bryan Zinser
// 02/09/15
// sum
#include <iostream>

using namespace std;

int main() {
	cout << "Input numbers [0 to quit]: ";
	float tmp = 0;
	float total = 0;
	cin >> tmp;
	while (tmp != 0) {
		if (tmp > 0) {
			total += tmp;
		}
		cin >> tmp;
	}
	if (total == 0) {
		cout << "Nothing to be done, have a great day." << endl;
	}
	else {
		cout << "Total sum is: " << total << endl;
	}
}