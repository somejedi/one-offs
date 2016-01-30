#include "compute.h"

int main() {
	ifstream fin("../database.txt");
	ofstream fout("../check.txt");
	Check check;
	string date, name, dollars, cents, payee;

	parseDb(fin, check);
	writeCheck(fout, check);
}