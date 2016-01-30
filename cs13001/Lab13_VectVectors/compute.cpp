#include "compute.h"

void init(vector<vector<bool>>& shots, int column, int row) {
	for (vector<vector<bool>>::iterator ip=shots.begin(); ip != shots.end(); ++ip) {
		for (vector<bool>::iterator pi=*ip->begin(); pi != *ip->end(); ++pi) {
			*pi = false;
		}
	}
	shots [5][5] = true;
}

void print(vector<vector<bool>>& shots) {
	for (vector<vector<bool>>::iterator ip=shots.begin(); ip != shots.end(); ++ip) {
		for (vector<bool>::iterator pi=*ip->begin(); pi != *ip->end(); ++pi) {
			if (*pi == true) {
				cout << "* ";
			} else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}