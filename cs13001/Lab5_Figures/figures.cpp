// playing with functions and header files
// bryan zinser
// 02/16/2015

void solidSquare(int size) {
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}
void hollowSquare(int size) {
	for (int y = 0; y < size; y++) {
		if (y == 0 || y == size - 1) {
			for (int x = 0; x < size; x++) {
				cout << "*";
			}
		}
		else {
			cout << "*";
			for (int x = 1; x < size - 1; x++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << endl;
	}
}

void leftTriangle(int size) {
	int tmp = size;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < tmp; x++) {
			cout << "*";
		}
		tmp--;
		cout << endl;
	}
	cout << endl;
}
void rightTriangle(int size) {
	for (int y = 0; y < size; y++) {
		for (int i = 0; i < y; i++) {
			cout << " ";
		}
		for (int x = 0; x < size - y; x++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}
