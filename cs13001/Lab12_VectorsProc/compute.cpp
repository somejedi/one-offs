#include "compute.h"

void print(vector<int>& v) {
	cout << "your numbers: ";
	for(vector<int>::iterator ip=v.begin(); ip != v.end(); ++ip) {
		cout << *ip << " ";
	}
	cout << endl;
}

void add(vector<int>& v, int value) {
	for (vector<int>::iterator ip=v.begin(); ip != v.end(); ++ip) {
		if (*ip == value) {
			return;
		}
	}
	vector<int>::iterator ip=v.end();
	v.insert(ip, value);
}

void remove(vector<int>& v, int value) {
	for (vector<int>::iterator ip=v.begin(); ip != v.end(); ++ip) {
		if (*ip == value) {
			v.erase(ip);
			return;
		}
	}

}