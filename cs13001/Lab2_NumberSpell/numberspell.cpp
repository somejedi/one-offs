// Spells out numbers from 1-99
// Bryan Zinser
// 01/26/2015

#include <iostream>
#include <string>

using namespace std;

int main() {
	int numberToRead;
	cout << "Please enter a number from 1-99: ";
	cin >> numberToRead;
	bool checkNumber = false;
	while (checkNumber == false) {
		if (numberToRead <= 0 || numberToRead >= 100) {
			cout << numberToRead << " is not between 1 and 99, please try again: ";
			cin >> numberToRead;
		}
		else {
			checkNumber = true;
		}
	}
	string lowNumbers[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };
	if (numberToRead < 20) {
		cout << lowNumbers[numberToRead] << endl;
	} else if (numberToRead >= 20 && numberToRead <= 29) {
		if (numberToRead == 20) {
			cout << "Twenty" << endl;
		} else {
			cout << "Twenty " << lowNumbers[numberToRead - 20] << endl;
		}
	} else if (numberToRead >= 30 && numberToRead <= 39) {
		if (numberToRead == 30) {
			cout << "Thirty" << endl;
		} else {
			cout << "Thirty " << lowNumbers[numberToRead - 30] << endl;
		}
	} else if (numberToRead >= 40 && numberToRead <= 49) {
		if (numberToRead == 40) {
			cout << "Fourty" << endl;
		} else {
			cout << "Fourty " << lowNumbers[numberToRead - 40] << endl;
		}
	} else if (numberToRead >= 50 && numberToRead <= 59) {
		if (numberToRead == 50) {
			cout << "Fifty" << endl;
		} else {
			cout << "Fifty " << lowNumbers[numberToRead - 50] << endl;
		}
	} else if (numberToRead >= 60 && numberToRead <= 69) {
		if (numberToRead == 60) {
			cout << "Sixty" << endl;
		} else {
			cout << "Sixty " << lowNumbers[numberToRead - 60] << endl;
		}
	} else if (numberToRead >= 70 && numberToRead <= 79) {
		if (numberToRead == 70) {
			cout << "Seventy" << endl;
		} else {
			cout << "Seventy " << lowNumbers[numberToRead - 70] << endl;
		}
	} else if (numberToRead >= 80 && numberToRead <= 89) {
		if (numberToRead == 80) {
			cout << "Eighty" << endl;
		} else {
			cout << "Eighty " << lowNumbers[numberToRead - 80] << endl;
		}
	} else if (numberToRead >= 90 && numberToRead <= 99) {
		if (numberToRead == 90) {
			cout << "Ninety" << endl;
		} else {
			cout << "Ninety " << lowNumbers[numberToRead - 90] << endl;
		}
	}

};
