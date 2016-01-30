#include <iostream>

using namespace std;

int main() {
	cout << "Input number between [1-100]: ";
	int n = 0;
	cin >> n;
	// loops forever until user selects 1-10
	while ( n <= 0 || n > 100) {
		cout << "Please try again: ";
		cin >> n;
	}
	cout << endl;
	// first square
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++ ) {
			cout << "*";
		}
		cout << endl;
	}	
	cout << endl;
	int tmp = n;
	// first triangle
	for (int y = 0; y < n; y++ ) {
		for (int x = 0; x < tmp; x++) {
			cout << "*";
		}
		tmp--;
		cout << endl;
	}
	cout << endl;
	// second triangle
	for (int y = 0; y < n; y++) {
		for (int i = 0; i < y; i++) {
			cout << " ";
		}
		for ( int x = 0; x < n-y; x++ ) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	// second square
	for (int y = 0; y < n; y++) {
		if (y==0 || y==n-1) {
			for (int x = 0; x < n; x++) {
				cout << "*";
			}
		} else {
			cout << "*";
			for ( int x = 1; x < n-1; x++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << endl;
	}
}
