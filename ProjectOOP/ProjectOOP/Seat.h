#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"

class Seat {
private:
	string seatId="";
	int* seatNumber = 0;
	char Row='A';   //From A to Z
	string Hall="E1";  //Ex: E1, A12 etc.
	Location* Zone;
	bool isAvailable = false;

	const int NO_SEATS_PER_ROW;

public:

	// getters

	const int getNoSeatsPerRow() {
		return Seat::NO_SEATS_PER_ROW;
	}

	string getSeatId() {
		this->seatId = seatId;
	}

	int* getSeatNumber() {
		int* copy = new int[this->NO_SEATS_PER_ROW];
		for (int i = 0; i < this->NO_SEATS_PER_ROW; i++){
			copy[i] = this->seatNumber[i];
	}
		return copy;
	}

	char getRow() {
		return this->Row;
	}

	string getHall() {
		return this->Hall;
	}

	bool getAvailability() {
		return this->isAvailable;
	}

	//setters

	void setSeatId();
	void setSeatNumber();
	void setRow();
	void setHall();
	void setAvailability();



};