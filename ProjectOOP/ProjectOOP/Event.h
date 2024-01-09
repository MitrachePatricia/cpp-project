#pragma once
#include "Location.h"
#include "Util.h"
#include "seat.h"
#include <string>
#include <iostream>
using namespace std;

enum GenreType { ROMANCE = 10, DRAMA, HORROR, THRILLER, COMEDY, ANIMATED };

class Event {
protected:
	const char* eventName = nullptr;
	char date[11];      // dd/mm/yyy
	char startingHour[6];       // hh:mm
	int duration = 0;       // in min
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

	//getters

	string getEventName();
	char* getDate();
	char* getStartingHour();
	int getDuration();

	// default constructor

	Event();

	//constructor with parameters

	Event(const char* eventName, const char* date, const char* startingHour, int duration);

	//destructor

	~Event();

	//Operators

	Event operator=(const Event& OtherEvent);

	Event operator+(int value);
	bool operator>(int value);

	friend void operator<<(ostream& console, Event& newEvent);
	friend void operator>>(istream& console, Event& newEvent);

	//virtual

	virtual void printEventInfo() {
		cout << endl << "The event " << this->eventName << " will take place on "
			<< this->date << " at " << this->startingHour << " and it's duration is " << this->duration << " minutes.";
	}

};

class Movie :public Event {
	GenreType type;

	void setGenreType(GenreType genre);
	GenreType getGenreType();
	static string genreTypeToString(GenreType genre);
public:
	Movie(const char* name, const char* date, const char* startHour, int duration, GenreType type) : Event(name, date, startHour, duration) {
		this->type = type;
	}

	void printMovieInfo() {
		this->Event::printEventInfo();
		cout << endl << "The genre of the movie is: " << this->type;
	}
};

class Play :public Event {
public:
	Play(const char* name, const char* date, const char* startHour, int duration) : Event(name, date, startHour, duration) {

	}
};

class Opera : public Event {
	string singerName;
public:
	Opera(const char* name, const char* date, const char* startHour, int duration, string sName) :
		Event(name, date, startHour, duration), singerName(sName) {

	}
};