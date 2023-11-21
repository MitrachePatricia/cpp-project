#pragma once
#include "Event.h"
#include "Location.h"
#include "Util.h"
#include "main.cpp"

enum TicketType { ONLINE, PREPAID, CASH };

class Ticket {
private:
	char* ticketId = nullptr;
	double price = 0;
	Event* name;
	Event* type;
	Location* name;
	Location* type;
	TicketType type;

	static int NO_VALID_TICKETS;

public:
	char* getTicketId() {
		return this->ticketId;
	}

	double getPrice() {
		return this->price;
	}
};