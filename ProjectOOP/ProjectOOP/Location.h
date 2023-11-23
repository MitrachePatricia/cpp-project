#pragma once
#include <string>
#include "Util.h"
#include "main.cpp"

enum class ZoneType { STAND1, STAND2, CATEGORY1, CATEGORY2, BOX, VIP, NORMAL };

class Location {
private:
	char* locationId=nullptr;
	const string locationName;
	ZoneType type;

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

    ZoneType getZoneType() {
		this->type = type;
	}

	//setters

	void setLocationId();
	void setType();

	//default constructor

	Location(string locationName) : locationName(locationName) {
	}
};
