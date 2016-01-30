// variable size container class implemented with vectors
// Mikhail Nesterenko
// 11/07/2009


#ifndef VECTORSOO_H_
#define VECTORSOO_H_

#include <vector>
using std::vector;

class vectorsoo{
public:
   vectorsoo(); // void constructor
   int vectorSize() const; // returns vector size

   int check(int number) const; // returns index of element containg
                                // "number" or -1 if none
   void addNumber(int);    // adds number to the array
   void removeNumber(int); // deletes the number from the array
   void output();      // prints the values of the array

  // note that the big three member functions are not needed
  // as vector class handles dynamic allocation properly 
  // by itself

private:
  vector<int> container;
};

#endif /* VECTORSOO_H_ */