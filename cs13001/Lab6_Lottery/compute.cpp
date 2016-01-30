//main library for lottery program
//bryan zinser
//02/16/2015

#include "compute.h"

void initialize(int wins[]){
	for (int i = 0; i < numNum; i++) {
		wins[i] = -1;
	}
}

bool check(int wins[], int numToCheck) {
	for (int i = 0; i < numNum; i++) {
		if (wins[i] == numToCheck && wins[i] >= 0) {
			return true;
		}
	}
	return false;
}

void draw(int wins[]) {
	int numOfSelectedElements = 0;
	int randomNum;
	while (numOfSelectedElements < numNum) {
		srand(time(nullptr));
		randomNum = rand() % 100;
		if (!check(wins, randomNum)){
			wins[numOfSelectedElements] = randomNum;
			numOfSelectedElements++;
		}
	}
}

int entry(){
	int numPicked;
	cout << "Please enter a number between 0 and 99: ";
	cin >> numPicked;
	while (numPicked > 99 || numPicked < 0) {
		cout << "Number not between 0 and 99, try again: ";
		cin >> numPicked;
	}
	return numPicked;
}

void printOut(int wins[], int numPicked){
	bool won = false;
	cout << "Number picked: " << numPicked << endl;
	cout << "Winning numbers were: ";
	for (int i = 0; i < numNum; i++) {
		cout << wins[i] << " ";
		if (numPicked == wins[i]){
			won = true;
		}
	}
	cout << endl;
	if (won) {
		cout << "CONGRATS, YOU WON!" << endl;
	}
	else {
		cout << "Please deposit $40 :)" << endl;
	}
}
