#pragma once
#include "main.cpp"

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
	static string zoneTypeToString(ZoneType type) {
		switch (type) {
		case ZoneType::STAND1:
			return "Stand 1";
		case ZoneType::STAND2:
			return "Stand 2";
		case ZoneType::CATEGORY1:
			return "Category 1";
		case ZoneType::CATEGORY2:
			return "Category 2";
		case ZoneType::BOX:
			return "Box";
		case ZoneType::VIP:
			return "VIP";
		case ZoneType::NORMAL:
			return "Normal";
		default:
			throw exception("You may not have a seat at this event.");

		}
	}
	
	static string eventTypeToString(EventType type) {
		switch (type) {
		case EventType::SPORTSMATCH:
			return "Sportsmatch";
		case EventType::MOVIE:
			return "Movie";
		case EventType::THEATRE:
			return "Theatre";
		default:
			throw exception("Event is unknown/inexistent.");

		}
	}
};