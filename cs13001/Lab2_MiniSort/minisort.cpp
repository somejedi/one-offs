// fixes minisort progrm
// Bryan Zinser
// 01/26/2015

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	cout << "Enter three numbers: ";
	int one, two, three;
	cin >> one >> two >> three;

	int tmp;
	// switchs postion one and two if one is greater than two
	if (one > two) {
		tmp = one;
		one = two;
		two = tmp;
	}
	//switches postion two and three if two is greater than three
	if (two > three) {
		tmp = two;
		two = three;
		three = tmp;
	}
	// switches postion one and two if one is greater than two
	if (one > two) {
		tmp = one;
		one = two;
		two = tmp;
	}

	cout << "The sorted numbers are: ";
	cout << one << " " << two << " " << three << endl;
}
