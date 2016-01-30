#ifndef COMPUTE_H
#define COMPUTE_H

#include <iostream>
using namespace std;

const int OCEAN_LENGTH = 5;
const int OCEAN_WIDTH = 5;

void init(bool [][OCEAN_WIDTH]);
void print(bool [][OCEAN_WIDTH]);
void fire(bool [][OCEAN_WIDTH], int, char);

#endif
