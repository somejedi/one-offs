#include "battleship.h"
#include <iostream>

using namespace std;

int main() {
	ship myFleet[FLEET_SIZE];
	initialize(myFleet);
	deploy(myFleet);
	while (operational(myFleet)){
		printFleet(myFleet);
		location myLoc = fire();
		int checkCheck = check(myFleet, myLoc);
		if (checkCheck != -1) {
			sink(myFleet[checkCheck]);
			printShip(myFleet[checkCheck]);
		} else {
			cout << "miss" << endl;;
		}
	}
	cout << "Congrats, you won!" << endl;
}