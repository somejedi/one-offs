#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
string spellOutNumber(string number);
string spellOutBigNumber(string number);

int main(){
	for (int i = 0; i < 100000000000; i++) {
		cout << i << " = " <<  spellOutBigNumber(to_string(i)) << endl;
	}
}

string spellOutNumber(string number){
	int temp1, temp2, temp3, temp4;
	string lowNumbers[20] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };
	string middleNumbers[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};
	switch (number.length()){
		case 1:
			temp1 = stoi(number);
			return lowNumbers[temp1];
	 	case 2:
	 		temp1 = stoi(number.substr(0,1));
	 		temp2 = stoi(number.substr(1,1));
	 		temp3 = stoi(number);
	 		if (temp1 > 1){
	 			return middleNumbers[temp1] + " " + lowNumbers[temp2];
	 		} else {
	 			return lowNumbers[temp3];
	 		}
	 	case 3:
	 		temp1 = stoi(number.substr(0,1));
	 		temp2 = stoi(number.substr(1,1));
	 		temp3 = stoi(number.substr(2,1));
	 		temp4 = stoi(number.substr(1,1) + number.substr(2,1));
	 		if (temp2 > 1){
	 			return lowNumbers[temp1] + " Hundred " + middleNumbers[temp2] + " " + lowNumbers[temp3];
	 		} else {
	 			if (temp4 == 0) {
	 				return lowNumbers[temp1] + " Hundred";
	 			} else {
	 				return lowNumbers[temp1] + " Hundred " + lowNumbers[temp4];
	 			}
	 		}
	}
}

string spellOutBigNumber(string number){
	if (number == "0") {
		return "Zero";
	}
	string bigNumbers[] = {"", "Thousand", "Million", "Billion", "Trillion", "Quadrillion", "Quintillion", "Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion", "Undecillion", "Duodecillion", "Tredecillion", "Quattuordecillion", "Quindecillion", "Sexdecillion", "Septendecillion", "Octodecillion", "Novemdecillion", "Vigintillion"};
	string outPut = "";
	int numberLength = number.length();
	int numberGroups = number.length() / 3;
	int numberLeftOver = number.length() % 3;
	if (numberLeftOver != 0) {
		numberGroups += 1;
	}
	switch (numberLeftOver) {
		case 1:
			outPut += spellOutNumber(number.substr(0,1)) + " " + bigNumbers[numberGroups - 1] + " ";
			number = number.substr(1);
			numberGroups -= 1;
			break;
		case 2:
			outPut += spellOutNumber(number.substr(0,2)) + " " + bigNumbers[numberGroups - 1] + " ";
			number = number.substr(2);
			numberGroups -= 1;
			break;
	}
	while (numberGroups > 0) {
		outPut += spellOutNumber(number.substr(0,3)) + " " + bigNumbers[numberGroups - 1] + " ";
		number = number.substr(3);
		numberGroups -= 1;
	}
	return outPut;
}
