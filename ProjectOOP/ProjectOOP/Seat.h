#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"

enum class SeatType { VIP, NORMAL, SPECIALNEEDS }; //Special needs 

class Seat {
private:
	char seatId[4];  //A01-A14, H01-H14  //dynamically Allocated char vector :D

	Location* Hall;
	SeatType type;
	bool isAvailable = false;

	const int NO_SEATS_PER_ROW;

public:

	//setters


	void setSeatId(const char* newSeatId) {
		delete[] this->seatId;
		if (strlen(newSeatId) > 3)
			throw exception("Wrong fromat of seat introduced.");
		if (newSeatId[0] < 'A' || newSeatId[0]>'H') {
			throw exception("The row does not exist");
		}

		if (newSeatId[1] * 10 + newSeatId[2] > Seat::NO_SEATS_PER_ROW || newSeatId[1] * 10 + newSeatId[2] < 0) {  //We verify if the number of the seat
			throw exception("The seat does not exist");
		}
		strcpy_s(seatId, strlen(newSeatId) + 1, newSeatId);
	}

	// getters

	const int getNoSeatsPerRow() {
		return Seat::NO_SEATS_PER_ROW;
	}

	char* getSeatId() {
		return this->seatId;
		return nullptr;
	}

	SeatType getSeatType() {	
		this->type = type;
	}


	bool isAvailable() {
		return this->isAvailable;
	}

	
};