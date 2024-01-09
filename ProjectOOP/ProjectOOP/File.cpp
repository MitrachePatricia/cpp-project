#include <fstream>
#include "File.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>

using namespace std;

char File::fileName[] = "data.txt";

void File::openFile() {
	ifstream dataGiven("data.txt");

	if (!dataGiven.is_open()) {
		throw exception("File is missing.");

	}
}



/*
void File::loadData() {
	//insert location
	Location Afi("Afi Cotroceni");
	Location MegaMall("Mega Mall");
	Location Theatre("Small Theatre Bucharest");
	Location Opera1("Bucharest National Opera House");

	//insert events
	Movie* NES = new Movie("Nightmare on the Elm Street", "01 / 12 / 2024", "17:30", 85, HORROR);
	Movie* HC = new Movie("Human Centipede", "12/04/2024", "23:00", 94, HORROR);

	Play* Hamlet=new Play("Hamlet", "12/12/2024", "10:20", 120);
	Play* Iona=new Play("Iona", "13/12/2024", "13:30", 140);

	Opera* Phantom = new Opera("Phantom of the Opera", "23/01/2025", "11:00", 180, "Dani Mocanu");

	//WHY DOES IT SAY THAT THE NAME IS CONSTANT CHAR I CHANGED IT TO STRING????????????

}*/