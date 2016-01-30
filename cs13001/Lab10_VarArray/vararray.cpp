#include "vararray.h"

void output(int *arrayPtr, int size) {
	cout << "Array containts [";
	for (int i = 0; i < size; i++) {
		if (i == size-1) {
			cout << arrayPtr[i];
		} else {
			cout << arrayPtr[i] << ", ";
		}
	}
	cout << "]" << endl;
}

int check(int *arrayPtr, int number, int size) {
	for (int i = 0; i < size; i++) {
		if (number == arrayPtr[i]) {
			return i;
		}
	}
	return -1;
}

void addNumber(int *& arrayPtr, int number, int &size) {
	for (int i = 0; i < size; i++) {
		if (number == arrayPtr[i]) {
			return;
		}
	}
	size += 1;
	int *a = new int[size];
	a = arrayPtr;
	a[size-1] = number;
	arrayPtr = a;
}

void removeNumber(int *& arrayPtr, int number, int &size) {
	int index = -1;
	index = check(arrayPtr, number, size);
	if (index == -1) {
		return;
	} else {
		for (int i = index; i < size; i++) {
			arrayPtr[i] = arrayPtr[i + 1];
		}
	}
	size -= 1;
	int *a = new int[size];
	a = arrayPtr;
	arrayPtr = a;
}