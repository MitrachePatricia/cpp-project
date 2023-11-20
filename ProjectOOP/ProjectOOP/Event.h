#pragma once
#include "Location.h"
	

enum class EventType{SPORTMATCH, MOVIE, THEATRE};

class Event {
private:
	char* name=nullptr;
	char date[11];      // dd/mm/yyy
	char time[6];       // hh/mm
	int duration=0;       // in min
	int breakDuration=0;  // in min
	EventType type;
	Location* name;
};