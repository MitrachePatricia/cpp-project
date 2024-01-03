#include "Location.h"

int Location::MAX_NO_SEATS = 200;

void Location::setLocationId(int newLocationId) {
	if (newLocationId != 0)
		this->locationId =newLocationId;
}

void Location::setHall(string newHall) {
	if (newHall.size() < 2 || newHall.size() > 3) {
		throw exception("Wrong number of characters introduced");
	}
	if (newHall[0] < 'A' || newHall[0]>'E') {
		throw exception("There is no such hall");
	}

	this->Hall = newHall;

}

void Location::setRunningEvents(unsigned int runningEvents) {
	if (runningEvents != 0)
		this->runningEvents = runningEvents;
	else throw exception("There are no running events right now.");
}

int Location::getLocationId() {
		return this->locationId;
}	

string Location::getHall() {
	return this->Hall;

}

Location Location::operator=(const Location& newLocation) {
	this->setHall(newLocation.Hall);
	this->setLocationId(newLocation.locationId);
	this->setRunningEvents(newLocation.runningEvents);
	return *this;
}

bool Location::operator!=(const Location& newLocation) {
	if (this->Hall != newLocation.Hall)
		return true;
	else
		return false;
}

Location Location::operator++(int) {
	Location updatedRunningEvents=*this;
	updatedRunningEvents++;
	return updatedRunningEvents;

}

Location::~Location() {
	MAX_NO_SEATS--;
}

void operator<<(ostream& console, Location& location) {
	console << "*****************";
	console << "\nThe location id is:" << location.getLocationId();
	console << "\nThe hall is:" << location.getHall();
}

void operator>>(istream& console, Location& location) {
	cout << "Insert the desired hall:";
	string newHall;
	console >> newHall;
	location.setHall(newHall);
}
