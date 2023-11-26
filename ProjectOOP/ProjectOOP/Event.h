#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"
#include "seat.h"
	
enum GendreType { ROMANCE = 10, DRAMA, HORROR, THRILLER, COMEDY, ANIMATED };

class Event {
private:
	const char* eventName = nullptr;
	const char* date[11];      // dd/mm/yyy
	char startingHour[6];       // hh:mm
	int duration = 0;       // in min
	GendreType gendre;
	Location* locationName;
	Seat* seatNumber;
	Seat* row;

public:

	//setters

	void setEventName(const char* newEventName);
	void setDate(const char* newDate);
	void setStartingHour(const char* newStartingHour);
	void setDuration(int newDuration);

	//getters

	string getEventName();
	char* getDate();
	char* getStartingHour();
	int getDuration();
	GendreType getGendreType();

	// default constructor

	Event() : eventName("No name") {
		this->setDate("01/01/2020");
		this->setDuration(92);
		this->setStartingHour("14:30");
	}

	//constructor with parameters

	Event(const char* eventName, char* date, char* startingHour, int duration) : eventName(eventName), duration(duration) {
		this->setDate(date);
		this->setStartingHour(startingHour);
	}

	//destructor

	~Event();

	//Operators

	//copy operator

	Event operator=(const Event& newEvent);

	//

	//stream operators


};