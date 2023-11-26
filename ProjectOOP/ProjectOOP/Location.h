#pragma once
#include <string>
#include "Util.h"
#include "main.cpp"

class Location {
private:
	int locationId;
	string Hall = "E1";  //Ex: A1-A9, E1-E9 etc.
	unsigned int runningEvents=0;

	static int MAX_NO_SEATS;
	static unsigned int TOTAL_LOCATIONS;

public:

	//setters

	void setLocationId(int newLocationId);
	void setHall(string newHall);
	void setRunningEvents(unsigned int runningEvents);

	//getters

	int getLocationId();
	static int getMaxNoSeats() {
		return Location::MAX_NO_SEATS;
	}
	string getHall();

	//default constructor

	Location(string locationName) {
		this->setHall("H9");
		this->setLocationId(435);
	}
	~Location();

	// Operators :)

	   //copy operator
	Location operator=(const Location& newLocation);

	   //compare operators
	bool operator!=(const Location& newLocation);
	//Location operator++(int);

	   //stream operators
	   
	friend void operator<<(ostream& console, Location &location);
	friend void operator>>(istream& console, Location& location);
	 
};
