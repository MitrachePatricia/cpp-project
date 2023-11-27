#pragma once
#include "Location.h"
#include "Util.h"
#include <string>
#include <iostream>
using namespace std;

enum SeatType { VIP = 20, NORMAL, SPECIALNEEDS }; //Special needs 

class Seat {
private:
	const char* seatId=nullptr;  //A01-A14, H01-H14  //dynamically Allocated char vector :D
	int seatNumber;
	char row;
	//Location* Hall;
	SeatType type;
	bool isAvailable = true;

	const int NO_SEATS_PER_ROW = 10;

public:

	//setters


	void setSeatId(string newSeatId);
	void setRow(char newRow);
	void setSeatNumber(int newSeatNumber);
	void setSeatType(SeatType newType);
	void Available();
	void notAvailable();
	int setAvailability(bool isAvailable);

	// getters

	const int getNoSeatsPerRow();
	string getSeatId();
	int getSeatNumber();
	SeatType getSeatType();
	char getRow();

	//constructors

	Seat();
	Seat(int seatNumber, char row);

	//destructor

	~Seat();

	//operators

	Seat operator=(const Seat& OtherSeat);

	bool operator==(Seat newSeat);            //We find out if there was an overwrite of the tickets
	Seat operator *=(int value);

	friend void operator<<(ostream& console, Seat& newSeat);
	friend void operator>>(istream& console, Seat& newSeat);
};