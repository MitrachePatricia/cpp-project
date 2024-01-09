#pragma once
#include <fstream>
#include <iostream>


class File {
public:
	static char fileName[];

	void openFile();
	void saveData();
	void loadData();
	void readFile();
};
