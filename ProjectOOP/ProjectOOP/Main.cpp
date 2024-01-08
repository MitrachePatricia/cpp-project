#include <iostream>
#include <string.h>
using namespace std;
#include "Location.h"
#include "Event.h"
#include "Seat.h"
#include "Ticket.h"
#include "Util.h"

	void baseMenu(int choice) {
		cout << "//-----------------------------//" << endl;
		cout << "//===Welcome to the app!=======//" << endl;
		cout << "//===Please select an option===//" << endl;
		cout << "//-----------------------------//" << endl;
		cout << "1. Request a ticket" << endl;
		cout << "2. Details about an existing ticket" << endl;
		cout << "3. See availabile events" << endl;
		cout << "4. Add an event" << endl;
		cout << "//-----------------------------//" << endl;
		cout << "5. Save & Exit" << endl;
		cout << "//-----------------------------//" << endl;
		cout << ">"; cin >> choice;

		if (choice >= 0 && choice <= 6)
			switch (choice) {
			case 0:
				break;
			case 1:
				option1();
				break;
			case 2:
				option2();
				break;
			case 3:
				option3();
				break;
			case 4:
				option4();
				break;
			default:
				throw exception("Error!");
				break;
			}

	}

	void option1() {

	}

	void option2();

	void option3();

	void option4();

	int main() {
	}