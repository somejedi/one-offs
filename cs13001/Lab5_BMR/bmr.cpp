// calcs bmr for men and women
// bryan zinser
// 02/16/2015

#include <iostream>

using namespace std;

const int cpb = 354; // calories per bagel

double bmrWoman(int weight, int height, int age);
double bmrMan(int weight, int height, int age);

int main(){
	char gender;
	int weight, heightFeet, heightInches, heightTotal, age;
	double tempbmr;
	bool keepRunning = true;
	cout << "Weight in pounds: ";
	cin >> weight;
	cout << "Height in feet & inches: ";
	cin >> heightFeet >> heightInches;
	heightTotal = (heightFeet * 12) + heightInches; // convert from feet to inches
	cout << "Age in years: ";
	cin >> age;
	cout << "Gender(m/f): ";
	cin >> gender;
	while (keepRunning) {
		switch (gender){
		case 'm':
			tempbmr = bmrMan(weight, heightTotal, age);
			cout << "Your BMR is: " << tempbmr << endl;
			cout << "That means you can eat " << int(tempbmr / cpb) << " medium-sized bagels per day." << endl;
			keepRunning = false;
			break;
		case 'f':
			tempbmr = bmrWoman(weight, heightTotal, age);
			cout << "Your BMR is: " << tempbmr << endl;
			cout << "That means you can eat " << int(tempbmr / cpb) << " medium-sized bagels per day." << endl;
			keepRunning = false;
			break;
		default:
			cout << "Gender not \"m\" or \"f\", please try again: ";
			cin >> gender;
			keepRunning = true;
			break;
		}
	}
}

double bmrWoman(int weight, int height, int age) {
	return 655 + (4.3*weight) + (4.7*height) - (4.7*age);
}

double bmrMan(int weight, int height, int age) {
	return 66 + (6.3*weight) + (12.9*height) - (6.8*age);
}