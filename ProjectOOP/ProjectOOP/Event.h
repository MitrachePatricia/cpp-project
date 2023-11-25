#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"
#include "seat.h"
	

class Event {
private:
	const char* eventName = nullptr;
	char date[11];      // dd/mm/yyy
	char startingHour[6];       // hh:mm
	int duration = 0;       // in min
	Location* locationName;
	Seat* seatNumber;
	Seat* row;

public:

	//getters
	string getEventName() {
		if (this->eventName != nullptr)
			return string(this->eventName);
		else
			return "";
	}
	char* getDate() {
		return Util::copyString(this->date);
	}

	char* getStartingHour() {
		return Util::copyString(this->startingHour);
	}

	int getDuration() {
		return this->duration;
	}

	
	//setters

	void setEventName(const char* newEventName) {
		if (newEventName[0] < 'A' || newEventName[0]>'Z')
			throw exception("There are no movies ");

		this->eventName = Util::copyString(newEventName);
	}
	void setDate(const char* newDate) {
		if (strlen(newDate) != 10) {
			throw exception("The introduced date is wrong!");
		}
		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("The data format is wrong");
		}

		strcpy_s(this->date, newDate);
	}
	void setStartingHour(const char* newStartingHour) {
		if (strlen(newStartingHour) != 5) {
			throw exception("The introduced hour is wrong!");
		}
		if (newStartingHour[2] != ':') {
			throw exception("The hour format is wrong");
		}

		strcpy_s(this->startingHour, newStartingHour);
	}

	void setDuration(int newDuration) {
		this->duration = newDuration;
	}

	// default constructor

	Event() : eventName("No name") {
		this->setDate("01/01/2020");
		this->setDuration(92);
		this->setStartingHour("14:30");
	}

	//destructor

	~Event() {
		delete[] this->eventName;
	}

};