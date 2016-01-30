// takes info, prints check
// bryan zinser
// 02/16/2015

#include "compute.h"

int main() {
	string date, name, payee, secondLine, thirdLine, dollars, cents;

	cout << "date: ";
	getline(cin, date);

	cout << "name: ";
	getline(cin, name);

	cout << "amount, dollars: ";
	getline(cin, dollars);

	cout << "cents: ";
	getline(cin, cents);

	cout <<  "payee: ";
	getline(cin, payee);

	// now we start printing the check
	cout << endl << "your check: " << endl << endl;

	// first line
	cout << name;
	addSpace(name.size());
	cout << date << endl;

	// second line
	secondLine = "pay to: " + payee;
	cout << secondLine;
	addSpace(secondLine.size());
	cout << "$" + dollars + "." + cents << endl;

	//third line
	thirdLine = spellNumber(stoi(dollars)) + " and " + cents + "/100";
	cout << thirdLine;
	addSpace(thirdLine.size());
	cout << "dollars" << endl;
	
}
