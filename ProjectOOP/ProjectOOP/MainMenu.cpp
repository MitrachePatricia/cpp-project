#include <iostream>
#include <string.h>
using namespace std;
#include "Location.h"
#include "Event.h"
#include "Seat.h"
#include "Ticket.h"
#include "Util.h"
#include "MainMenu.h"

	void MainMenu::baseMenu() {
		int choice;
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

	void MainMenu::option1() {
		Movie NES("Nightmare on the Elm Street", "01/12/2024", "17:30", 85, HORROR);
		Movie HC("Human Centipede", "12/04/2024", "23:00", 94, HORROR);

		Play Hamlet("Hamlet", "12/12/2024", "10:20", 120);
		Play Iona("Iona", "13/12/2024", "13:30", 140);

		Opera Phantom("Phantom of the Opera", "23/01/2025", "11:00", 180, "Dani Mocanu");

		cout << "//-------------------------------//" << endl;
		cout << "//===Creating a new ticket...===//" << endl;
		cout << "//-----------------------------//" << endl;
		cout << "Available events: " << endl;
		Event* availableEvents[5];
		availableEvents[0] = &NES;
		availableEvents[1] = &HC;
		availableEvents[2] = &Hamlet;
		availableEvents[3] = &Iona;
		availableEvents[4] = &Phantom;

		for (int i = 0; i < 5; i++) {
			availableEvents[i]->printEventInfo();
		}
	}

	void MainMenu::option2() {
		string ticket;
		cout << "Please insert your ticket id:";
		cout << ">";
		cin >> ticket;

		if (ticket.size() !=9){
			throw exception("Wrong format");
		}
		//i wanted to show details about the ticket (for what event it is for and all details) but im unable to D:

	}

	void MainMenu::option3() {
		Movie NES("Nightmare on the Elm Street", "01/12/2024", "17:30", 85, HORROR);
		Movie HC("Human Centipede", "12/04/2024", "23:00", 94, HORROR);

		Play Hamlet("Hamlet", "12/12/2024", "10:20", 120);
		Play Iona("Iona", "13/12/2024", "13:30", 140);

		Opera Phantom("Phantom of the Opera", "23/01/2025", "11:00", 180, "Dani Mocanu");
		cout << "Available events: " << endl;
		Event* availableEvents[5];
		availableEvents[0] = &NES;
		availableEvents[1] = &HC;
		availableEvents[2] = &Hamlet;
		availableEvents[3] = &Iona;
		availableEvents[4] = &Phantom;

		for (int i = 0; i < 5; i++) {
			availableEvents[i]->printEventInfo();
		}
	}

	void MainMenu::option4() {
		int insert;
		string newName;
		string newDate;
		string newStartingHour;
		int newDuration;
		string type;
		cout << endl<< "Please insert which new Event you want to add:";
		cout << endl << "1. Movie";
		cout << endl << "2. Play";
		cout << endl << "3. Opera";
		cout << endl << ">"; cin >> insert;

		cout << endl << "Please insert the name of the event: ";
		cin >> newName;
		cout << endl << "Please insert the date of the event: ";
		cin >> newDate;
		cout << endl << "Please insert the starting hour of the event: ";
		cin >> newStartingHour;
		cout << endl << "Please insert the duration of the event: ";
		cin >> newDuration;
		if (insert == 1) {
			cout << "Please insert the genre of the event (full caps): ";
			cin >> type;
		}

		/*
		switch (insert) {
		case 1:
			Movie(newName, newDate, newStartingHour, newDuration, type);
		case 2:
			Play(newName,newDate, newStartingHour,newDuration);         //i don't know
		case 3:
			Opera(newName,newDate, newStartingHour, newDuration);
		default:
			throw exception("Not an option!");
			break;
		}
		*/

	}