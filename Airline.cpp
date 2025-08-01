#include "Airline.h"
#include <iostream>
#include<string.h>
#include<cstdlib>
#include<fstream>
using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

Airline::Airline() {
	cout << BLUE << "\t\t\t\t___________________Islamabad Airlines___________________ \n" << RESET << endl;
	cout << CYAN << "\t\t\t\t___________________Main Menu____________________________" << RESET << endl;
	cout << GREEN << "\t\t\t\t_________________________________________________________" << endl;
}


void Airline :: writeairdetails() {
	ofstream outFile("Airline management oop proj.txt", ios::app);
	outFile << "\t___________________Islamabad Airlines___________________ \n" << endl;
	outFile << "\t___________________Main Menu____________________________" << endl;
	outFile << "\t_________________________________________________________" << endl;
	outFile << "\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;

}

void Passenger::putdetails(int i) {
	bool b;
	do {
		b = false;
		try {
			cout << CYAN << "\n\t\tPlease Enter valid details below: " << RESET;
			cout << GREEN << "\n\t\t| Details for Passenger " << i + 1 << ". | " << RESET;
			cout << "\n\t\tName: ";
			cin >> passengername[i];
			cout << "\n\t\tSurname: ";
			cin >> passengersurname[i];
			cout << "\n\t\tGender(Male/Female): ";
			cin >> gender[i];
			cout << "\n\t\tAge (0-95): ";
			cin >> passengerage[i];
			if (passengerage[i] <= 0 || passengerage[i] >= 95)
				throw invalid_argument("Invalid age");

			cout << "\n\t\tPassenger ID (13 digits): ";
			cin >> passengerid[i];
			if (passengerid[i].length() != 13)
				throw invalid_argument("Invalid CNIC length");

			cout << "\n\t\tPhone number (11 digits): ";
			cin >> phonenumber[i];
			if (phonenumber[i].length() != 11)
				throw invalid_argument("Invalid phone number");

			cout << "\n\t\tEmail ID (........@gmail.com): ";
			cin >> emailid[i];

			cout << "\n\t\tAddress: ";
			cin >> address[i];
		}
		catch (const invalid_argument& e) {
			cout << RED << "\n\t\tException: " << e.what() << RESET << endl;
			b = true;
		}
	} while (b);
}
void Passenger::displaypassengerdetails(int i) {
	cout << YELLOW << "\n\t\tPASSENGERS DETAILS: " << RESET;
	cout << GREEN <<  "\n\t\tName: " << passengername[i];
	cout << GREEN << "\n\t\tPassenger Surname: " << passengersurname[i];
	cout << GREEN <<"\n\t\tGender: " << gender[i];

	if (passengerage[i] > 0 && passengerage[i] < 95)
		cout << GREEN<<"\n\t\tAge: " << passengerage[i];
	else
		cout << RED << "\n\t\tInvalid age" << RESET;

	cout << GREEN << "\n\t\tPassenger ID (without dashes): ";
	if (passengerid[i].length() == 13)
		cout << GREEN << passengerid[i] << RESET;
	else
		cout << RED << "\n\t\tInvalid Entry!" << RESET;

	cout << GREEN << "\n\t\tPhone number: ";
	if (phonenumber[i].length() == 11)
		cout << GREEN << phonenumber[i] << RESET;
	else
		cout << RED << "\n\t\tInvalid Entry!" << RESET;

	cout << GREEN << "\n\t\tEmail: " << emailid[i];
	cout << GREEN << "\n\t\tAddress: " << address[i];
}
void Passenger::writepastofile(ofstream& file, int i)
{
	ofstream outFile("Airline management oop proj.txt", ios::app);
	
	if ((passengerage[i] > 0 && passengerage[i] < 95) && (passengerid[i].length() == 13) && (phonenumber[i].length() == 11))
	{
		outFile << "\n Name " << passengername[i] << "\tSurname " << passengersurname[i];

		outFile << "\n AGE  ";
		outFile << passengerage[i];

		outFile << "\n Gender " << gender[i];

		outFile << "\nCNIC  " << passengerid[i];


		outFile << "\nPhone Number " << phonenumber[i];
	}
	else
	{
		outFile << "\n\t\tInvalid Entry!";
		exit(0);
	}
		
	
}

void Flight::flights(int i) {
	cout << BLUE << "\n\n\t\tFLIGHT DESTINATIONS:" << RESET;
	string flightN[6] = { "Lahore", "Karachi", "Peshawar", "Multan", "Quetta", "Skardu" };

	for (int a = 0; a < 6; a++) {
		cout << " \n\t\t" << (a + 1) << ". Flight to " << CYAN << flightN[a] << RESET;
	}

	cout << BLUE << "\n\n\t\tFLIGHT DETAILS: ";
	cout <<RED<< "\n\t\tWelcome to the Islamabad Airlines!" << endl;
	cout << RED<<"\n\t\tPress the number of the city for which you want to book the flight: ";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "\t\t___" << flightN[choice - 1] << "__\n" << endl;
		cout << BLUE << "\t\tYour comfort is our priority. Enjoy the journey!" << RESET << endl;
		charges[i] = 14000;
		flightid[i] = rand();
		cout <<GREEN<< "\n\t\tFlight ID: " << flightid[i];
		cout << GREEN<<"\n\t\tYou have successfully booked the flight to Lahore" << endl;
		break;
	case 2:
		cout << "\t\t___" << flightN[choice - 1] << "__\n" << endl;
		cout << BLUE << "\t\tYour comfort is our priority. Enjoy the journey!" << RESET << endl;
		charges[i] = 20000;
		flightid[i] = rand();
		cout << GREEN << "\n\t\tFlight ID: " << flightid[i];
		cout << GREEN << "\n\t\tYou have successfully booked the flight to Karachi" << endl;
		break;
	default:
		cout << RED << "\t\tInvalid input!" << RESET << endl;
		break;
	}
}

void Flight::writeflighttofile(ofstream& file, int i) {
	ofstream outFile("Airline management oop proj.txt", ios::app);
		outFile <<"\nFlight ID " << flightid[i] << "\nCharges " << charges[i] << endl;
		
	
}

void Ticket::addtickets(int i) {
	
		cout << "\n\t\tEnter your Flight type (Business or Economy):";
		cin >> flighttype[i];
		ticketIDs[i] = rand(); 
		ticketPrices[i] = calculateTicketPrice(i);
	
}
void Ticket::displaytickets(int i) {
	cout << YELLOW<<"\n\n\t\tTICKET DETAILS: ";
	
		cout << "\n\t\tTicket ID: " << ticketIDs[i];
		cout << "\n\t\t";
		displaypassengerdetails(i); 
		
		cout << "\n\t\tTicket Price: $" << ticketPrices[i] << endl;
	
		
}
double Ticket::calculateTicketPrice(int a) {
	double basePrice = 100.0;
	double priceMultiplier = (flighttype[a] == "business") ? 1.5 : 1.0;


	double destinationMultiplier = 1.2;

	return basePrice * priceMultiplier * destinationMultiplier;
}
void Ticket::writeticktofile(ofstream& file, int i) {
	ofstream outFile("Airline management oop proj.txt", ios::app);
		outFile <<"\n Flight Type" << flighttype[i] << "\n Ticket ID " << ticketIDs[i] << "\n Ticket Price " << ticketPrices[i] << endl;
		outFile.close();
}
void luggage::luggagedetails(int i) {
	cout << YELLOW<<"\n\n\t\tEnter Number of Luggages: ";
	cin >> no_ofluggages;
	cout <<GREEN<< "\n\t\tLuggage Details:";
	cout <<GREEN<< "\n\t\tNumber of luggages: " << no_ofluggages;
	
		for (int j = 1; j <= no_ofluggages; j++) {
			luggageid[i] = rand();
			cout <<GREEN<< "\n\t\tLuggage ID: " << luggageid[i]<<"\n";
		}
		
	
}
void luggage::writelugtofile(ofstream& file, int i) {
	ofstream outFile("Airline management oop proj.txt", ios::app);
		outFile <<"\nluggage ID "<< luggageid[i] << endl;
		
}
void Noticeboard::details() {
	cout << YELLOW << "\n\n\t\tFlights From Islamabad Departure          Arrival         Status";
	cout << GREEN << "\n\t\tIslamabad to Lahore    09:30 AM          10:30 AM         On Time";
	cout << GREEN << "\n\t\tIslamabad to Karachi   10:45 AM          12:30 PM         On Time";
	cout << GREEN << "\n\t\tIslamabad to Peshawar  01:00 PM          01:45 PM         Delayed";
	cout << GREEN << "\n\t\tIslamabad to Multan    02:00 PM          03:00 PM         Delayed";
	cout << GREEN << "\n\t\tIslamabad to Quetta    03:20 PM          04:20 PM         On Time";
	cout << GREEN << "\n\t\tIslamabad to Skardu    04:30 PM          05:30 PM        Cancelled";
	cout << "\n";
	cout << YELLOW << "\n\t\tFlights To Islamabad   Departure          Arrival         Status";
	cout << RED << "\n\t\tLahore to Islamabad    09:30 AM          10:30 AM         On Time";
	cout << RED << "\n\t\tKarachi to Islamabad   10:45 AM          12:30 PM         Delayed";
	cout << RED << "\n\t\tPeshawar to Islamabad  01:00 PM          01:45 PM        Cancelled";
	cout << RED << "\n\t\tMultan to Islamabad    02:00 PM          03:00 PM         On Time";
	cout << RED << "\n\t\tQuetta to Islamabad    03:20 PM          04:20 PM         Delayed";
	cout << RED << "\n\t\tSkardu to Islamabad    04:30 PM          05:30 PM         On Time";
	cout << RED << "\n";
	
}
void Noticeboard::writenottofile(ofstream& file) {
	ofstream outFile("Airline management oop proj.txt", ios::app);
	if (outFile.is_open()) {
		outFile << "\n\t\t\t\tNOTICE BOARD \n";
		outFile << "\n\n\t\tFlights From Islamabad Departure          Arrival         Status";
		outFile << "\n\t\tIslamabad to Lahore    09:30 AM          10:30 AM         On Time";
		outFile << "\n\t\tIslamabad to Karachi   10:45 AM          12:30 PM         On Time";
		outFile << "\n\t\tIslamabad to Peshawar  01:00 PM          01:45 PM         Delayed";
		outFile << "\n\t\tIslamabad to Multan    02:00 PM          03:00 PM         Delayed";
		outFile << "\n\t\tIslamabad to Quetta    03:20 PM          04:20 PM         On Time";
		outFile << "\n\t\tIslamabad to Skardu    04:30 PM          05:30 PM        Cancelled";
		outFile << "\n";
		outFile << "\n\t\tFlights To Islamabad   Departure          Arrival         Status";
		outFile << "\n\t\tLahore to Islamabad    09:30 AM          10:30 AM         On Time";
		outFile << "\n\t\tKarachi to Islamabad   10:45 AM          12:30 PM         Delayed";
		outFile << "\n\t\tPeshawar to Islamabad  01:00 PM          01:45 PM        Cancelled";
		outFile << "\n\t\tMultan to Islamabad    02:00 PM          03:00 PM         On Time";
		outFile << "\n\t\tQuetta to Islamabad    03:20 PM          04:20 PM         Delayed";
		outFile << "\n\t\tSkardu to Islamabad    04:30 PM          05:30 PM         On Time";
		outFile << "\n";
		
	}
	else {
		cerr << "Unable to open file for writing." << endl;
	}


}
void Boardingandcheck_in::check_in() {
	cout <<GREEN<< "\n\n\t\tAll Documents are valid! Check in Complete";
}
void Boardingandcheck_in::boardingpassgeneration(int i) {
	
		cout <<YELLOW<< "\n\n\t\tPassenger: " << passengername[i] << "  " << passengersurname[i];

		cout <<BLUE<< "\n\n\t\tDeparture From: Islamabad";
		
		if (choice == 1) {
			cout << GREEN << "\n\t\tDeparture Time: 09:30 AM ";
			cout << GREEN << "\n\t\tTo: Lahore";
			cout << GREEN << "\n\t\tArrival Time: 10:30 AM";
			cout << "\n\t\t";
		}
		else if (choice == 2) {
			cout << GREEN << "\n\t\tDeparture Time: 10:45 AM";
			cout << GREEN << "\n\t\tTo: Karachi";
			cout << GREEN << "\n\t\tArrival Time: 12:30 PM";
			cout << "\n\t\t";
		}
		else if (choice == 3) {
			cout << GREEN << "\n\t\tDepartue Time: 01:00 PM";
			cout << "\n\t\tTo: Peshawar";
			cout << "\n\t\tArrival Time: 01:45 PM";
			cout << "\n\t\t";
		}
		else if (choice == 4) {
			cout << GREEN << "\n\t\tDeparture Time: 02:00 PM";
			cout << GREEN << "\n\t\tTo: Multan";
			cout << GREEN << "\n\t\tArrival Time: 03:00 PM";
			cout << "\n\t\t";
		}
		else if (choice == 5) {
			cout << GREEN << "\n\t\tDeparture Time: 03:20 PM";
			cout << GREEN << "\n\t\tTo: Quetta";
			cout << GREEN << "\n\t\tArrival Time: 04:20 PM";
			cout << "\n\t\t";
		}
		else if (choice == 6) {
			cout << GREEN << "\n\t\tDeparture Time: 04:30 PM";
			cout << GREEN << "\n\t\tTo: Skardu:";
			cout << GREEN << "\n\t\tArrival Time: 05:30 PM";
			cout << "\n\t\t";
		}
		cout << GREEN << "\n\t\tFlight Number: " << flightid[i];
		cout << GREEN << "\n\t\tTicket Number:" << ticketIDs[i];
		cout << "\n\t\t";
	
}
void Boardingandcheck_in::writeboard_tofile(ofstream& file, int i) {
	ofstream outFile("Airline management oop proj.txt", ios::app);
	if (outFile.is_open()) {
		outFile << "\n\n\t\tPassenger details " << passengername[i] << "  " << passengersurname[i];

		outFile << "\n\n\t\tDeparture From: Islamabad";

		if (choice == 1) {
			outFile << "\n\t\tDeparture Time: 09:30 AM ";
			outFile << "\n\t\tTo: Lahore";
			outFile << "\n\t\tArrival Time: 10:30 AM";
		}
		else if (choice == 2) {
			outFile << "\n\t\tDeparture Time: 10:45 AM";
			outFile << "\n\t\tTo: Karachi";
			outFile << "\n\t\tArrival Time: 12:30 PM";
		}
		else if (choice == 3) {
			outFile << "\n\t\tDepartue Time: 01:00 PM";
			outFile << "\n\t\tTo: Peshawar";
			outFile << "\n\t\tArrival Time: 01:45 PM";
		}
		else if (choice == 4) {
			outFile << "\n\t\tDeparture Time: 02:00 PM";
			outFile << "\n\t\tTo: Multan";
			outFile << "\n\t\tArrival Time: 03:00 PM";
		}
		else if (choice == 5) {
			outFile << "\n\t\tDeparture Time: 03:20 PM";
			outFile << "\n\t\tTo: Quetta";
			outFile << "\n\t\tArrival Time: 04:20 PM";
		}
		else if (choice == 6) {
			outFile << "\n\t\tDeparture Time: 04:30 PM";
			outFile << "\n\t\tTo: Skardu:";
			outFile << "\n\t\tArrival Time: 05:30 PM";

			outFile << "\n\t\tFlight Number: " << flightid[i];
			outFile << "\n\t\tTicket Number:" << ticketIDs[i];
		}
	}
}
