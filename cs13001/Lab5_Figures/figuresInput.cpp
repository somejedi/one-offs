// core functions
// bryan zinser
// 02/16/2015
#include "figures.h"

int main() {
	while (true) {
		int inOption, size;
		char squareOption;
		cout << "1. square" << endl;
		cout << "2. left triangle" << endl;
		cout << "3. right triangle" << endl;
		cout << "select figure: ";
		cin >> inOption;
		cout << "select size: ";
		cin >> size;
		switch (inOption) {
		case 1:
			cout << "filled or hollow [f/h]: ";
			cin >> squareOption;
			while (true) {
				if (squareOption != 'f' && squareOption != 'h') {
					cout << "please select f or h: ";
					cin >> squareOption;
				}
				else {
					break;
				}
			}
			if (squareOption == 'f') {
				solidSquare(size);
			}
			else {
				hollowSquare(size);
			}
			break;
		case 2:
			leftTriangle(size);
			break;
		case 3:
			rightTriangle(size);
			break;
		default:
			cout << "1-3 not selected, goodbye" << endl;
			return false;
		}
	}
}
