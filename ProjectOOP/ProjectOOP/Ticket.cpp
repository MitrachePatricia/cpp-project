#include "Ticket.h"

void Ticket::setTicketId(string tId) {
	this->ticketId = Util::copyString(tId.c_str());
}

void Ticket::setPrice(double newPrice) {
	this->price = newPrice;
}

char* Ticket::getTicketId() {
	return this->ticketId;
}

double Ticket::getPrice() {
	return this->price;
}

int Ticket::getUniqueId() {
	static atomic<uint32_t> ticketId{ 0 };    // found it here https://stackoverflow.com/questions/66951451/generate-a-unique-id-c
	return ticketId;
}