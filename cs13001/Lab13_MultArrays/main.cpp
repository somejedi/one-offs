#include "compute.h"

int main() {
	bool shots[OCEAN_LENGTH][OCEAN_WIDTH];
	char j; int i; bool finished = false; char in;
	init(shots);
	print(shots);
	while (!finished) {
		cout << "Location? ";
		cin >> j >> i;
		fire(shots, i, j);
		print(shots);
		cout << "Another shot? [y/n] ";
		cin >> in;
		if (in != 'y') {
			finished = true;
		}
	}
}