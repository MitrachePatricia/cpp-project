#pragma once
#include <string>
#include "Util.h"
#include "main.cpp"

class Location {
private:
	char* locationId=nullptr;
	string Hall = "E1";  //Ex: A1-A9, E1-E9 etc.
	const string locationName;

	static int MAX_NO_SEATS;

public:

	//getters

	string getLocationId() {
		if (this->locationId != nullptr)
			return string(this->locationId);
		else
			return "";
	}

	static int getMaxNoSeats() {
		return Location::MAX_NO_SEATS;
	}

	string getHall() {
		return this->Hall;
	}

	//setters

	void setLocationId(string newLocationId) {
		delete[] this->locationId;
		this->locationId = Util::copyString(newLocationId.c_str());
	}

	void setHall(string newHall) {
		if (newHall.size() < 2 || newHall.size() > 3) {
			throw exception("Wrong number of characters introduced");
		}
		if (newHall[0] < 'A' || newHall[0]>'E') {
			throw exception("There is no such hall");
		}

		this->Hall = newHall;

	}

	//default constructor

	Location(string locationName) : locationName(locationName) {
		this->setHall("H9");
		this->setLocationId("102A");
	}

	~Location() {
		delete[] this->locationId;
	}
};
