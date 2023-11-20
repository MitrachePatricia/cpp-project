#pragma once
#include <string>

enum class ZoneType { STAND1, STAND2, CATEGORY1, CATEGORY2, BOX, VIP, NORMAL };

class Location {
private:
	int locationId=0;
	string locationName=nullptr;
	ZoneType type;

	static int MAX_NO_SEATS;
	const int NO_SEATS_PER_ROW;
};
