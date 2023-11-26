#include "Event.h"


void Event::setEventName(const char* newEventName) {
	if (newEventName[0] < 'A' || newEventName[0]>'Z')
		throw exception("There are no movies ");

	this->eventName = Util::copyString(newEventName);
}

void Event::setDate(const char* newDate) {
	if (strlen(newDate) != 10) {
		throw exception("The introduced date is wrong!");
	}
	if (newDate[2] != '/' || newDate[5] != '/') {
		throw exception("The data format is wrong");
	}

	memcpy(this->date, newDate,9);
}

void Event::setStartingHour(const char* newStartingHour) {
	if (strlen(newStartingHour) != 5) {
		throw exception("The introduced hour is wrong!");
	}
	if (newStartingHour[2] != ':') {
		throw exception("The hour format is wrong");
	}

	strcpy_s(this->startingHour, newStartingHour);
}

void Event::setDuration(int newDuration) {
	if (duration < 20)
		throw exception("There can't be such a short event.");
	this->duration = newDuration;
}

string Event::getEventName() {
	if (this->eventName != nullptr)
		return string(this->eventName);
	else
		return "";
}
char* Event::getDate() {
	return Util::copyString(this->date);
}

char* Event::getStartingHour() {
	return Util::copyString(this->startingHour);
}

int Event::getDuration() {
	return this->duration;

}
