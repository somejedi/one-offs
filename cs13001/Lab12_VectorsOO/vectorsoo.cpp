#include "vectorsoo.h"
#include <iostream>

using namespace std;


vectorsoo::vectorsoo() {	
}

/*
int vectorsoo::vectorSize() const {
	return container.size();
}


int vectorsoo::check(int number) const {
	for (vector<int>::const_iterator ip=container.begin(); ip != container.end(); ++ip) {
		if (*ip == number) {
			return ip; //can't convert from const vector to int, no idea how to fix
		}
	}
	return -1;
}
*/

void vectorsoo::addNumber(int number) {
	for (vector<int>::iterator ip=container.begin(); ip != container.end(); ++ip) {
		if (*ip == number) {
			return;
		}
	}
	vector<int>::iterator ip=container.end();
	container.insert(ip, number);
}

void vectorsoo::removeNumber(int number) {
	for (vector<int>::iterator ip=container.begin(); ip != container.end(); ++ip) {
		if (*ip == number) {
			container.erase(ip);
			return;
		}
	}
}

void vectorsoo::output() {
	cout << "your numbers: ";
	for(vector<int>::iterator ip=container.begin(); ip != container.end(); ++ip) {
		cout << *ip << " ";
	}
	cout << endl;
}