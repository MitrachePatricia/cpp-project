#pragma once
#include <string>
#include "Util.h"
#include "main.cpp"

enum class ZoneType { STAND1, STAND2, CATEGORY1, CATEGORY2, BOX, VIP, NORMAL };

class Location {
private:
	string locationId=nullptr;
	const string locationName;
	ZoneType type;

	static int MAX_NO_SEATS;
	const int NO_SEATS_PER_ROW;

public:
	string getLocationId() {
		return this->locationId;
	}

	string getLocationName() {
		return this->locationName;
	}

	static int getMaxNoSeats() {
		return Location::MAX_NO_SEATS;
	}

	const int getNoSeatsPerRow() {
		return Location::NO_SEATS_PER_ROW;
	}

	void setZoneType(ZoneType type) {
		this->type = type;
	}

};
