// compute header
// bryan zinser
// 02/16/2015
#ifndef COMPUTE_H
#define COMPUTE_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int numNum = 10;

void initialize(int wins[]);
bool check(int wins[], int numToCheck);
void draw(int wins[]);
int entry();
void printOut(int wins[], int numPicked);

#endif
