#pragma once
#include "Location.h"
#include "Util.h"
#include "seat.h"
#include <string>
#include <iostream>
using namespace std;
	
enum GendreType { ROMANCE = 10, DRAMA, HORROR, THRILLER, COMEDY, ANIMATED };

class Event {
private:
	const char* eventName = nullptr;
	char date[11];      // dd/mm/yyy
	char startingHour[6];       // hh:mm
	int duration = 0;       // in min
	GendreType gendre;
	//Location* locationName;
	//Seat* seatNumber;
	//Seat* row;

	static int NO_RUNNING_EVENTS;

public:

	//setters

	void setEventName(const char* newEventName);
	void setDate(const char* newDate);
	void setStartingHour(const char* newStartingHour);
	void setDuration(int newDuration);
	void setGendreType(GendreType gendre);

	//getters

	string getEventName();
	char* getDate();
	char* getStartingHour();
	int getDuration();
	GendreType getGendreType();
	static string gendreTypeToString(GendreType gendre);

	// default constructor

	Event();

	//constructor with parameters

	Event(const char* eventName, char* date, char* startingHour, int duration);

	//destructor

	~Event();

	//Operators

	Event operator=(const Event& OtherEvent);

	Event operator+(int value);
	bool operator>(int value);

	friend void operator<<(ostream& console, Event& newEvent);
	friend void operator>>(istream& console, Event& newEvent);

};