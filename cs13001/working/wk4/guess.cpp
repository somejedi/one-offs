#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(0)); // nullptr wouldn't work with my compiler
	int chance = rand() % 100;
	int guess;
	cout << "I selected a number between 0 and 99, what is it? ";
	while (true) {
		cin >> guess;
		if (guess > chance) {
			cout << "Wrong, it is smaller, what is it? ";
			continue;
		} else if (guess < chance) {
			cout << "Wrong, it is larger, what is it? ";
			continue;
		} else {
			cout << "Correct!" << endl;
			return false;
		}
	}
}
