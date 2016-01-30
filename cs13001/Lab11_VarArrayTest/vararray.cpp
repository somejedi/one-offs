#include "vararray.h"
#include <iostream>
using namespace std;

varArray::varArray(){
	size = 0;
	dArray = new int[size];
}

varArray::varArray(const varArray &va) {
	size = va.size;
	dArray = new int[size];
	for (int i = 0; i < size; i++) {
		dArray[i] = va.dArray[i];
	}
}

varArray& varArray::operator=(const varArray &va) {
	if (this == &va) {
		return *this;
	}
	delete[] dArray;
	dArray = new int[va.size];
	size = va.size;
	for (int i = 0; i < size; i++) {
		dArray[i] = va.dArray[i];
	}
	return *this;
}

varArray::~varArray() {
	delete[] dArray;
}

void varArray::output(){
	cout << "Array contains [";
		for (int i = 0; i < size; i++) {
			if (i == size - 1) {
				cout << dArray[i];
			} else {
				cout << dArray[i] << ", ";
			}
		}
		cout << "]" << endl;
}

int varArray::check(int number){
	for (int i = 0; i < size; i++) {
		if (number == dArray[i]) {
			return i;
		}
	}
	return -1;
}

void varArray::addNumber(int number){
	int pos = check(number);
	if (pos == -1) {
		size += 1;
		int *p = new int[size];
		for (int i = 0; i < size - 1; i++) {
			p[i] = dArray[i];
		}
		p[size - 1] = number;
		delete[] dArray;
		dArray = p;
	}
}

void varArray::removeNumber(int number) {
	int pos = check(number);
	if (pos != -1) {
		for (int i = pos; i < size; i++) {
			dArray[i] = dArray[i + 1];
		}
		size -= 1;
		int *p = new int[size];
		for (int i = 0; i < size + 1; i++) {
			p[i] = dArray[i];
		}
		delete[] dArray;
		dArray = p;
	}
}