#include "battleship.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

location pick(){
	location loc;
	char a[] = {'a', 'b', 'c', 'd','e'};
	loc.x = rand() % 5;
	loc.y = a[rand() % 5];
	return loc;
}

void printShip(ship sh){
	cout << sh.loc.y << sh.loc.x;
	if (sh.sunk){
		cout << " sunk" << endl;
	} else {
		cout << " up" << endl;
	}
}

void printFleet(ship const sh[]){
	for (int i = 0; i < FLEET_SIZE; i++) {
		cout << sh[i].loc.y << sh[i].loc.x;
		if (sh[i].sunk){
			cout << " sunk, ";
		} else {
			cout << " up, ";
		}
	}
	cout << endl;
}


location fire() {
	char y;
	int x;
	location loc;
	cout << "Location? ";
	cin >> y >> x;
	loc.y = y;
	loc.x = x;
	return loc;
}

bool match(ship sh, location loc){
	if (sh.loc.x == loc.x && sh.loc.y == loc.y) {
		return true;
	} else {
		return false;
	}
}

void sink(ship &sh) {
	sh.sunk = true;
}

void initialize(ship sh[]){
	for (int i = 0; i < FLEET_SIZE; i++) {
		sh[i].loc.x = -1;
		sh[i].loc.y = 'f';
		sh[i].sunk = true;
	}
}

void deploy(ship sh[]){
	for (int i = 0; i < FLEET_SIZE; i++) {
		location loc = pick();
		bool checkCheck = true;
		while (checkCheck) {
			if (check(sh, loc) == -1) {
				sh[i].loc = pick();
				sh[i].sunk = false;
				checkCheck = false;
			}
		}
	}
}

bool operational(ship const sh[]) {
	bool oneUp = false;
	for (int i = 0; i < FLEET_SIZE; i++) {
		if(!sh[i].sunk)
			oneUp = true;
	}
	return oneUp;
}

int check(ship const sh[], location loc){
	int atIndex = -1;
	for (int i = 0; i < FLEET_SIZE; i++) {
		if (sh[i].loc.x == loc.x && sh[i].loc.y == loc.y) {
			atIndex = i;
			return atIndex;
		}
	}
	return atIndex;
}
