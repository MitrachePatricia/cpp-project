#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"

class Seat {
private:
	string seatId="";
	int seatNumber=0;
	char Row='A';   //From A to Z
	string Hall="E1";  //Ex: E1, A12 etc.
	Location* Zone;
	bool isAvailable=false;

public:
	string getSeatId() {
		this->seatId = seatId;
	}

	int getSeatNumber() {
		this->seatNumber = seatNumber;
	}

	char getRow() {
		return this->Row;
	}

	string getHall() {
		return this->Hall;
	}

	bool getAvailability() {
		if (this->isAvailable == false)
			return "Seat not available";
		else
			return "Seat available";
	}

};