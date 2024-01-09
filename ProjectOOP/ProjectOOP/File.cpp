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
