#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	while (true) {
		int n; // temp int
		double m; // temp double
		double l; // temp double
		int selection;
		cout << "1. absolute value" << endl;
		cout << "2. square root" << endl;
		cout << "3. ceiling" << endl;
		cout << "4. power" << endl;
		cout << "Select an operation: ";
		cin >> selection;
		switch (selection) {
		case 1:
			cout << "Enter value: ";
			cin >> n;
			cout << "The absolute value of " << n << " is: " << abs(n) << endl;
			break;
		case 2:
			cout << "Enter value: ";
			cin >> m;
			cout << "The square root of " << m << " is: " << sqrt(m) << endl;
			break;
		case 3:
			cout << "Enter value: ";
			cin >> m;
			cout << "The ceiling of " << m << " is: " << ceil(m) << endl;
			break;
		case 4:
			cout << "Enter base: ";
			cin >> m;
			cout << "Enter exponent: ";
			cin >> l;
			cout << "The result is: " << pow(m, l) << endl;
			break;
		default:
			cout << "Goodbye." << endl;
			return false;
		}
	}
}