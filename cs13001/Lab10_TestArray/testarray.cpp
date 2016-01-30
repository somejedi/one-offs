// tests variable size array implementation
// Mikhail Nesterenko
// 10/22/2014

#include "vararray.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;



int main(){

   int size=5;  // setting array size
   int *a = new int[5]; // allocating dynamic array

   // initializing array
   a[0] = 0; a[1] = 10; a[2] = 20; a[3] = 30; a[4] = 40;

   output(a, size); // printing out the array

   
   // asking user to input a number
   cout << "Input number to search for: ";
   int number;
   cin >> number;

   // checking if the input number is in the array 
   int index = check(a, number, size);
   if (index == -1)
      cout << "The number is not in the array" << endl;
   else
      cout << "The number is at position " << index << endl;


   // adding a new number to array
   addNumber(a, 55, size);
   cout << "Array after adding a new number: "; output(a, size);

   // adding a duplicate number to array
   // the function should not add it
   addNumber(a, 20, size);
   cout << "Array after adding existing number: "; output(a, size);

   // 
   removeNumber(a, 10, size);
   cout << "Array after removing number: "; output(a, size);

   removeNumber(a, 11, size);
   cout << "Array after removing number: "; output(a, size);


   delete [] a; // deallocating the array
}
