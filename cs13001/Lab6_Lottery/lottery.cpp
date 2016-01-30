//lottery game
//bryan zinser
//02/16/2015
#include "compute.h"

const int numNum = 10;

int main() {
	int wins[numNum];
	initialize(wins);
	draw(wins);
	int numPicked = entry();
	printOut(wins, numPicked);
}