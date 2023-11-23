#pragma once
#include "Location.h"
#include "Util.h"
#include "main.cpp"
	

enum class EventType{SPORTSMATCH, MOVIE, THEATRE};

class Event {
private:
	char* name = nullptr;
	char date[11];      // dd/mm/yyy
	char startingHour[6];       // hh/mm
	int duration = 0;       // in min
	int breakDuration = 0;  // in min
	EventType type;
	Location* name;

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
	int getBreakDuration() {
		return this->duration;
	}

	EventType getEventType() {
		this->type = type;
	}

	//setters

	void setName();
	void setDate();
	void setStartingHour();
	void setDuration();
	void setBreakDuration();

};