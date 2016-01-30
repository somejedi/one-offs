#include "compute.h"

int main() {
	cout << "enter ocean rows: ";
	int oceanRows;
	cin >> oceanRows;

	cout << "enter ocean columns: ";
	int oceanColumns;
	cin >> oceanColumns;

	vector<vector<bool>> shots;
	vector<bool> shotsRow(oceanRows);

	init(shots);
	print(shots);
}