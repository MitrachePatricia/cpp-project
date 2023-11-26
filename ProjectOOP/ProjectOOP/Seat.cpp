#include "Seat.h"

void Seat::setSeatId(string newSeatId) {
	if (sizeof(newSeatId) < 4) {
		throw exception("Wrong fromat of seatId introduced.");
	}
	this->seatId = Util::copyString(newSeatId.c_str());
}

void Seat::setRow(char newRow) {
	if (newRow < 'A' || newRow>'H') {
		throw exception("The row does not exist");
	}
	else
		this->row = (newRow);
}

void Seat::setSeatNumber(int newSeatNumber) {
	if (newSeatNumber > 0 && newSeatNumber < NO_SEATS_PER_ROW)
		this->seatNumber = newSeatNumber;
	else
		throw exception("The seat doesn't exist");
}

int Seat::setAvailability(bool isAvailable) {
	if (isAvailable == true)
		cout<< "The seat is available";
	else
		cout<< "The seat is not available";
}

void Seat::setSeatType(SeatType newType) {
	this->type = newType;
}

const int Seat::getNoSeatsPerRow() {
	return Seat::NO_SEATS_PER_ROW;
}

string Seat::getSeatId() {
	return this->seatId;
}

int Seat::getSeatNumber() {
	return this->seatNumber;
}

char Seat::getRow() {
	return this->row;
}

SeatType Seat::getSeatType() {
	return this->type = type;
}

void Seat::Available() {
	this->isAvailable = true;
}	

void Seat::notAvailable() {
	this->isAvailable = false;
	throw exception("The seat is unavailable.");
}

Seat::Seat():seatId(seatId){
	this->setRow('A');
	this->setSeatNumber(9);
}

Seat::Seat(int seatNumber, char row) : seatId(seatId) {
	this->setRow(row);
	this->setSeatNumber(seatNumber);
}

Seat::~Seat() {
	delete[] seatId;
}

Seat Seat::operator=(const Seat& OtherSeat) {
	this->setRow(OtherSeat.row);
	this->setSeatId(OtherSeat.seatId);
	this->setSeatNumber(OtherSeat.seatNumber);
}

bool Seat::operator==(Seat newSeat) {
	if (this->seatNumber == newSeat.seatNumber && this->row==newSeat.row)
		return true;
	else
		return false;
}

Seat Seat::operator*=(int value) {
	Seat numberOfSeats = *this;
	numberOfSeats *= value;
	return numberOfSeats;
}
	
void operator<<(ostream& console, Seat& seat) {
	console << "*****************";
	console << "\nThe seat id is:" << seat.getSeatId();
	console << "\nThe seat number is:" << seat.getSeatNumber();
	console << "\nThe row is: " << seat.getRow();
	console << "\n" << seat.isAvailable;
	console << "\n The seat type is:" << seat.getSeatType();
}

void operator>>(istream& console, Seat& newSeat) {
	cout << "Insert the id of the ticket:";
	char* newSeatId;
	console >> newSeatId;
	newSeat.setSeatId(newSeatId);

	cout << "Insert the seat type:";
	string type;
	console >> type;
	if (type == "VIP")
		newSeat.setSeatType(VIP);
	else
		if (type == "NORMAL")
			newSeat.setSeatType(NORMAL);
		else
			if
				(type == "SPECIALNEEDS")
				newSeat.setSeatType(SPECIALNEEDS);
			else
				throw exception("You do not have a seat");

	cout << "Insert the desired row:";
	char newRow;
	console >> newRow;
	newSeat.setRow(newRow);

	cout << "Insert the desired seat number:";
	int newSeatNumber;
	console >> newSeatNumber;
	newSeat.setSeatNumber(newSeatNumber);

}
