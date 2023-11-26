#include "Event.h"
#include <string>


int Event::NO_RUNNING_EVENTS = 0;

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
	strcpy_s(this->date, newDate);
}

void Event::setStartingHour(const char* newStartingHour) {
	if (strlen(newStartingHour) != 5) {
		throw exception("The introduced hour is wrong!");
	}
	if (newStartingHour[2] != ':') {
		throw exception("The hour format is wrong");
	}
	if (newStartingHour[0] > 2||newStartingHour[1]<0)
		throw exception("Wrong hour introduced");
	if (newStartingHour[0] == 2 && newStartingHour[1] > 4)
		throw exception("Wrong hour introduced");
	if (newStartingHour[3] > 5 || newStartingHour[3] < 0)
		throw exception("Wrong hour introduced");

	strcpy_s(this->startingHour, newStartingHour);
}

void Event::setDuration(int newDuration) {
	if (duration < 20)
		throw exception("There can't be such a short event.");
	this->duration = newDuration;
}

void Event::setGendreType(GendreType newGendre){
	this->gendre = newGendre;
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

GendreType Event::getGendreType() {
	return this->gendre;
}

string Event::gendreTypeToString(GendreType gendre) {
	switch (gendre) {
	case GendreType::ROMANCE:
		return "Romance";
	case GendreType::DRAMA:
		return "Drama";
	case GendreType::HORROR:
		return "Horror";
	case GendreType::THRILLER:
		return"Thriller";
	case GendreType::COMEDY:
		return "Comedy";
	case GendreType::ANIMATED:
		return"Animated";
	default:
		throw exception("There exists no such gendre.");
	}


}


void operator<<(ostream& console, Event& event) {
	console << "******************";
	console << "\n Event Name: " << event.getEventName();
	console << "\n The date of the event is: " << event.getEventName();
	console << "\n The starting hour of the event is: " << event.getStartingHour();
	console << "\n The duration of the event is: " << event.getDuration();
	console << "\n The gendre of the event is: " << event.getGendreType();

}

void operator>>(istream& console, Event& event) {
	cout << "Insert the desired event name: ";
	char* newEvent;
	console >> newEvent;
	event.setEventName(newEvent);

	cout << "Insert desired date for the event:";
	char* newDate;
	console >> newDate;
	event.setDate(newDate);

	cout << "Insert the duration:";
	int newDuration;
	console >> newDuration;
	event.setDuration(newDuration);

	//cout << "Insert the gendre";
	//string newGendre;
	//console >> newGendre;  //i dont know how to do this im sorry
}

Event::Event() : eventName("No name") {
	this->setDate("01/01/2020");
	this->setDuration(92);
	this->setStartingHour("14:30");
	NO_RUNNING_EVENTS++;
}

Event::Event(const char* eventName, char* date, char* startingHour, int duration) : eventName(eventName), duration(duration) {
	this->setDate(date);
	this->setStartingHour(startingHour);
	NO_RUNNING_EVENTS++;
}

Event::~Event() {
	NO_RUNNING_EVENTS--;
}

Event Event::operator=(const Event& OtherEvent) {
	this->setDate(OtherEvent.date);
	this->setDuration(OtherEvent.duration);
	this->setStartingHour(OtherEvent.startingHour);
	return *this;
}

Event Event::operator+(int value) {
	Event updatedDuration = *this;
	updatedDuration.duration += value;
	return updatedDuration;
}

bool Event::operator>=(const Event event) {
	char copy[2];
	strcpy_s(copy, 2, event.startingHour);
	copy[2] = NULL;
	if (copy[0] >= 1 && copy[2] >= 4)
		return true;
	else
		return false;
}