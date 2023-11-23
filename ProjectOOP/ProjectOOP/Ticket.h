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

	//getters
	char* getTicketId() {
		return this->ticketId;
	}

	double getPrice() {
		return this->price;
	}

	//setters
	
	void setTicketId(string tId) {
		delete[] this->ticketId;
		this->ticketId = Util::copyString(tId.c_str());
	}

	TicketType getTicketType() {
		this->type = type;
	}

	void setPrice();
};