#include "compute.h"

string addSpace(int size) {
	string var1 = "";
	while (size < checkLength) {
		var1 += " ";
		size++;
	}
	return var1;
}

string spellNumber(string number){
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

void parseDb(ifstream &fin, Check &check){
	string var1;
	getline(fin, var1);
	check.date = var1.substr(6);
	getline(fin, var1);
	check.name = var1.substr(6);
	getline(fin, var1);
	check.dollars = var1.substr(17);
	getline(fin, var1);
	check.cents = var1.substr(7);
	getline(fin, var1);
	check.payee = var1.substr(7);
	fin.close();
}

void writeCheck(ofstream &fout, Check check){
	string secondLine, thirdLine;
	fout << check.name;
	fout << addSpace(check.name.size());
	fout << check.date << endl;

	secondLine = "pay to: " + check.payee;
	fout << secondLine;
	fout << addSpace(secondLine.size());
	fout << "$" + check.dollars + "." + check.cents << endl;

	thirdLine = spellNumber(check.dollars) + " and " + check.cents + "/100";
	fout << thirdLine;
	fout << addSpace(thirdLine.size());
	fout << "dollars" << endl;
	fout.close();
}
