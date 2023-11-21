#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"

class Seat {
private:
	string seatId="";
	int number=0;
	char row='A';   //From A to Z
	string Hall="E1";  //Ex: E1, A12 etc.
	Location* Zone;
	bool isAvailable=false;

};