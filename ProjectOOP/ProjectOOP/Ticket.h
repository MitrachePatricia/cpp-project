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
	Event* EventName;
	Location* locationName;
	TicketType type;

	static int NO_VALID_TICKETS;
	static int getUniqueId();

public:

	//setters

	void setTicketId(string tId);
	TicketType getTicketType() {
		this->type = type;
	}
	void setPrice(double newPrice);

	//getters
	char* getTicketId();
	double getPrice();

	//default constructor

	Ticket() {
		this->setPrice(20);
		this->setTicketId("762A");
	}

	//destructor

	~Ticket(){ 
		delete[] this->ticketId; 
	}
};