#include <fstream>
#include "file.h"
#include "Location.h"
using namespace std;

char File::fileName[] = "data.txt";

void File::saveData(ofstream& file) {
	if (!file.is_open()) 
		throw exception("File is not opened");

}

void File::loadData() {
	//insert location
	Location Afi();
	Location MegaMall();

	Event Avampremiera("Nightmare on the Elm Street", "01/12/2024", "17:30", 85);
	Event LastScreeing("Human Centipede", "12/04/2024", "23:00", 94);

}