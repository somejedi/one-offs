#include "compute.h"

void addSpace(int size) {
	while (size < checkLength) {
		cout << " ";
		size++;
	}
}

string spellNumber(int numberToRead){
	string number = to_string(numberToRead);
	if (number == "0") {
		return "Zero";
	}
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
	return "";
}
