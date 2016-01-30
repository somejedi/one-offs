#include <iostream>

using std::cin; using std::cout; using std::endl;

void swap(int &a, int &b);

int main(){

  // inputs the numbers
  cout << "Enter three numbers: ";
  int one, two, three;
  cin >> one >> two >> three;

  int tmp;

  // orders one and two
  if (one > two){
    swap(one, two);
  }

  // orders one and three
  if (one > three){
    swap(one, three);
  }

  // orders two and three
  if (two > three){
    swap(two, three);
  }


  // outputs the sorted numbers
  cout << "The sorted numbers are: ";
  cout << one << " " << two << " " << three << endl;
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}