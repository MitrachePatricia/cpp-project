#include <fstream>
#include "file.h"
using namespace std;

char File::fileName[] = "data.txt";

void File::saveData(ofstream& file) {
	if (!file.is_open()) 
		throw exception("File is not opened");

}