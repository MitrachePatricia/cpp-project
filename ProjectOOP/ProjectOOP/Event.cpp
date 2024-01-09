#include "Event.h"
#include <string>
using namespace std;


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
	if (newStartingHour[0] > 2 || newStartingHour[1] < 0)
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

void Movie::setGenreType(GenreType newGendre){
	this->type = newGendre;
}

string Event::getEventName() {
		return this->eventName;
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

GenreType Movie::getGenreType() {
	return this->type;
}

string Movie::genreTypeToString(GenreType gendre) {
	switch (gendre) {
	case GenreType::ROMANCE:
		return "Romance";
	case GenreType::DRAMA:
		return "Drama";
	case GenreType::HORROR:
		return "Horror";
	case GenreType::THRILLER:
		return"Thriller";
	case GenreType::COMEDY:
		return "Comedy";
	case GenreType::ANIMATED:
		return"Animated";
	default:
		throw exception("There exists no such gendre.");
	}


}


void operator<<(ostream& console, Event& event) {
	console << "******************";
	console << "\n Event Name: " << event.eventName;
	console << "\n The date of the event is: " << event.date;
	console << "\n The starting hour of the event is: " << event.startingHour;
	console << "\n The duration of the event is: " << event.duration;

}

void operator>>(istream& console, Event& event) {
	cout << "Insert the desired event name: ";
	char* newEvent{};
	console >> newEvent;
	event.setEventName(newEvent);

	cout << "Insert desired date for the event:";
	char* newDate{};
	console >> newDate;
	event.setDate(newDate);

	cout << "Insert the duration:";
	int newDuration;
	console >> newDuration;
	event.setDuration(newDuration);
}

Event::Event() : eventName("No name") {
	this->setDate("01/01/2020");
	this->setDuration(92);
	this->setStartingHour("14:30");
	NO_RUNNING_EVENTS++;
}

Event::Event(const char* eventName, const char* date, const char* startingHour, int duration) : eventName(eventName) {
	this->setDate(date);
	this->setStartingHour(startingHour);
	this->setDuration(duration);
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

bool Event::operator>(int value) {
	char copy[2];
	strcpy_s(copy, 2, startingHour);
	copy[2] = NULL;
	if (copy[0] >= value/10 && copy[2] >= value%10)
		return true;
	else
		return false;
}