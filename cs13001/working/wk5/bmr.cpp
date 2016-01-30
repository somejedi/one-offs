#include <iostream>
#include <cmath>

using namespace std;

const int cpb = 354; // calories per bagel

double bmrWoman(int weight, int height, int age);
double bmrMan(int weight, int height, int age);

int main(){
	char gender;
	int weight, heightFeet, heightInches, heightTotal, age;
	double tempbmr;
	cout << "Weight in pounds: ";
	cin >> weight;
	cout << "Height in feet & inches: ";
	cin >> heightFeet >> heightInches;
	heightTotal = (heightFeet * 12) + heightInches; // convert from feet to inches
	cout << "Age in years: ";
	cin >> age;
	cout << "Gender(m/f): ";
	cin >> gender;
	cout << weight << " " << heightTotal << " " << age << " " << gender << endl;
	while (true) {
		switch(gender){
			case 'm':
				tempbmr = bmrMan(weight, heightTotal, age);
				cout << "Your BMR is: " << tempbmr << endl;
				cout << "That means you can eat " << ceil(tempbmr/cpb) << " medium-sized bagels per day." << endl;
				return false;				
			case 'f':
				tempbmr = bmrWoman(weight, heightTotal, age);
				cout << "Your BMR is: " << tempbmr << endl;
                                cout << "That means you can eat " << ceil(tempbmr/cpb) << " medium-sized bagels per day." << endl;
				return false;
			default:
				cout << "Gender not \"m\" or \"f\", please try again: ";
				cin >> gender;
				break;
		}
	}
}

double bmrWoman(int weight, int height, int age) {
        return 655+(4.3*weight)+(4.7*height)-(4.7*age);
}

double bmrMan(int weight, int height, int age) {
        return 66+(6.3*weight)+(12.9*height)+(6.8*age);
}
