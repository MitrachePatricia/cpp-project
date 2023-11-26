#include "Ticket.h"

int Ticket::NO_VALID_TICKETS = 200;

void Ticket::setTicketId(string tId) {
	if (NO_VALID_TICKETS == 0)
		throw exception("There are no more tickets available.");
	this->ticketId = Util::copyString(tId.c_str());
	NO_VALID_TICKETS--;	
}

static string ticketTypeToString(TicketType type) {
	switch (type) {
	case TicketType::CASH:
		return "Cash";
	case TicketType::ONLINE:
		return "Online";
	case TicketType::PREPAID:
		return "Prepaid";
	default:
		throw exception("Event is unknown/inexistent.");

	}
}

void Ticket::setPrice(double newPrice) {
	if (price < 0)
		throw exception("The introduced price is wrong");
	this->price = newPrice;
}

void Ticket::setTicketType(TicketType newType) {
	this->type = newType;
}

double Ticket::getPrice() {
	return this->price;
}

TicketType Ticket::getTicketType() {
	return this->type;
}

//int Ticket::getUniqueId() {
//	static atomic<uint32_t> ticketId{ 10 };    // found it here https://stackoverflow.com/questions/66951451/generate-a-unique-id-c
//	return ticketId;
//}

string Ticket::getTicketId() {
	if (this->ticketId != nullptr)
		return string(this->ticketId);
}

Ticket::Ticket():ticketId(ticketId){
	    this->setPrice(20);
	    this->setTicketId("762A");
}

Ticket::Ticket(const char* ticketId, double price): ticketId(ticketId){
	this->setTicketId(ticketId);
	this->setPrice(price);
}

Ticket::~Ticket() {
	delete[] ticketId;
	NO_VALID_TICKETS++;
}

Ticket Ticket:: operator=(const Ticket& OtherTicket) {
	this->setTicketId(OtherTicket.ticketId);
	this->setPrice(OtherTicket.price);
	this->setTicketType(OtherTicket.type);
	return *this;
}

Ticket Ticket::operator-=(int value) {
	Ticket updatedPrice = *this;
	updatedPrice -= value * price;
	return updatedPrice;
}

bool Ticket::operator<(int value) {
	if (NO_VALID_TICKETS < value)
		return true;
	else
		return false;
}

void operator<<(ostream& console, Ticket& ticket) {
	console << "*****************";
	console << "\nThe ticket id is:" << ticket.getTicketId();
	console << "\nThe ticket price was:" << ticket.getPrice();
	console << "\nThe ticket type is: " << ticket.getTicketType();
}

void operator>>(istream& console, Ticket& newTicket) {
	cout << "Insert the price of the ticket:";
	int newPrice;
	console >> newPrice;
	newTicket.setPrice(newPrice);

	cout << "Insert the ticket type:";
	string type;
	console >> type;
	if (type == "PREPAID")
		newTicket.setTicketType(PREPAID);
	else
		if (type == "CASH")
			newTicket.setTicketType(CASH);
		else
			if
				(type == "ONLINE")
				newTicket.setTicketType(ONLINE);
			else
				throw exception("NOT PAYED");
}