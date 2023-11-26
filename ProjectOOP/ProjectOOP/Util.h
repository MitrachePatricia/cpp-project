#pragma once
#include "main.cpp"
#include "Event.h"
#include "Location.h"
#include "Seat.h"
#include "Ticket.h"

class Util {
public:
	static char* copyString(const char* source) {
		if (source == nullptr) {
			return nullptr;
		}
		char* value = new char[strlen(source) + 1];
		strcpy_s(value, strlen(source) + 1, source);
		return value;
	}
};
