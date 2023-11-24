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
	static string seatTypeToString(SeatType type) {
		switch (type) {
		case SeatType::VIP:
			return "VIP";
		case SeatType::NORMAL:
			return "Normal";
		case SeatType::SPECIALNEEDS:
			return "Special Needs";
		default:
			throw exception("You may not have a seat at this event.");

		}
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
};