#pragma once
#include "Event.h"
#include "Location.h"
#include "Util.h"
#include <string>
#include <iostream>
using namespace std;

enum TicketType { ONLINE, PREPAID, CASH };

class Ticket {
private:
	const char* ticketId = nullptr;
	double price = 0;
	//Event* EventName;
	//Location* locationName;
	TicketType type;

	static int NO_VALID_TICKETS;

public:

	//setters

	void setTicketId(string tId);
	void setPrice(double newPrice);
	void setTicketType(TicketType newType);

	//getters
	double getPrice();
	TicketType getTicketType();

	//default constructor

	Ticket();

	//constructor with parameters

	Ticket(const char* ticketId, double price);

	//destructor

	~Ticket();

	//Operators

	Ticket operator=(const Ticket& OtherTicket);

	Ticket operator-=(double value);             //We apply a certain discount to the ticket
	bool operator<(int value);   //Verify if there are less than a certain number of seats

	friend void operator<<(ostream& console, Ticket& newTicket);
	friend void operator>>(istream& console, Ticket& newTicket);
};

class idGenerator {
private:
	const char allNumbers[11] = { "1234567890" };
	const int MAXRAND = 6;

public:
	char* getUniqueId() {
			char id[9];
			for (int i = 0; i < 10; i++)
				id[i] = allNumbers[rand() % MAXRAND];
	}
};