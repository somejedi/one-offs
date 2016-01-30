#ifndef COMPUTE_H
#define COMPUTE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const int checkLength = 40;

struct Check {
	string date;
	string name;
	string dollars;
	string cents;
	string payee;
};

string addSpace(int size);
string spellNumber(string number);

void parseDb(ifstream &fin, Check &check);
void writeCheck(ofstream &fout, Check check);

#endif