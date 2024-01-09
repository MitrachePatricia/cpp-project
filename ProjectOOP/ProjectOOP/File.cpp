#include <fstream>
#include "File.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>

using namespace std;

void File::openFile() {
	ifstream dataGiven("data.txt");

	if (!dataGiven.is_open()) {
		throw exception("File is missing.");
	}
	int locationId;
	dataGiven >> locationId;

	dataGiven.close();
}

void File::saveData() {
	ofstream binFile("data.bin", ios::ate);
	char* date[11];
	int size = 11;
	const char* ticketId;
	int size2 = 9;
	binFile.write((char*)&date, sizeof(char) * size);
	binFile.write((char*)&ticketId, sizeof(char) * size2);

	binFile.close();
}
