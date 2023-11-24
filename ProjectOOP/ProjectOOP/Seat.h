#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"

enum class SeatType { VIP, NORMAL, SPECIALNEEDS }; //Special needs 

class Seat {
private:
	string seatId="";
	int seatNumber = 0;
	char row='A';   //From A to H

	Location* Hall;
	SeatType type;
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
		return this->row;
	}

	SeatType getSeatType() {
		this->type = type;
	}


	bool isAvailable() {
		return this->isAvailable;
	}

	//setters

	void setSeatNumber(int newSeatNumber) {
		if (newSeatNumber > Seat::NO_SEATS_PER_ROW) {
			throw exception("The seat does not exist");
		}
		this->seatNumber = newSeatNumber;
	}
	void setRow(char newRow) {
		if (newRow < 'A' || newRow>'H') {
			throw exception("The row does not exist");
		}
	}

};