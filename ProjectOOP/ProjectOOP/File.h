#pragma once
#include <fstream>
#include <iostream>

class File {
public:
	static char fileName[];

	void saveData(ofstream& file);
	void loadData();
	void readFile();
};
