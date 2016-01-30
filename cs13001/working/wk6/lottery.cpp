#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int numNum = 10;

void initialize(int wins[]);
bool check(int wins[], int numToCheck);
void draw(int wins[]);
int entry();
void printOut(int wins[], int numPicked);

int main() {
	int wins[numNum];
	initialize(wins);
	draw(wins);
	int numPicked = entry();
	printOut(wins, numPicked);
}

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
		srand(time(0));
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
			bool won = true;
		}
	}
	cout << endl;
	if (won) {
		cout << "CONGRATS, YOU WON!" << endl;
	} else {
		cout << "Please deposit $40 :)" << endl;
	}
}