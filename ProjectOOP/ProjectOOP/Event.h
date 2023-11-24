#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"
#include "seat.h"
	

class Event {
private:
	char* name = nullptr;
	char date[11];      // dd/mm/yyy
	char startingHour[6];       // hh:mm
	int duration = 0;       // in min
	Location* name;
	Seat* seatNumber;
	Seat* row;

public:

	//getters
	string getName() {
		if (this->name != nullptr)
			return string(this->name);
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

	void setName(const char* newName) {
		if (newName[0] < 'A' || newName[0]>'Z')
			throw exception("There are no movies ");

		this->name = Util::copyString(newName);
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

};