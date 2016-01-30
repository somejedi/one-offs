#include "compute.h"

void init(bool shots[][OCEAN_WIDTH]) {
	for (int i = 0; i < OCEAN_LENGTH; i++) {
		for (int j = 0; j < OCEAN_WIDTH; j++) {
			shots[i][j] = false;
		}
	}
}

void print(bool shots[][OCEAN_WIDTH]) {
	cout << "  a b c d e" << endl;
	for (int i = 0; i < OCEAN_LENGTH; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < OCEAN_WIDTH; j++) {
			if (shots[i][j] == true) {
				cout << "* ";
			} else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void fire(bool shots[][OCEAN_WIDTH], int i, char j) {
	int tmpj;
	if (j == 'a') {
		tmpj = 0;
	} else if (j == 'b') {
		tmpj = 1;
	} else if (j == 'c') {
		tmpj = 2;
	} else if (j == 'd') {
		tmpj = 3;
	} else if (j == 'e') {
		tmpj = 4;
	} else {
		return;
	}
	shots[i-1][tmpj] = true;
}