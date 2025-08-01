#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Airline {
public:
	Airline();
	void writeairdetails();
};
class Passenger {
protected:
	string passengername[10];
	string passengersurname[10];
	int passengerage[10];
	string gender[10];
	string passengerid[10];
	string phonenumber[10];
	string emailid[10];
	string address[10];

public:
	void putdetails(int i);
	void displaypassengerdetails(int i);  
	void writepastofile(ofstream& file , int i);
};
class Flight : public Passenger {
protected:
	int choice;
	float charges[10];
	string flightN[6];
	int flightid[10];

public:
	void flights(int i);
	void writeflighttofile(ofstream& file, int i);
};

class Ticket : public Flight {
protected:
	string flighttype[10];
	int ticketIDs[10]; // Store ticket IDs
	double ticketPrices[10]; // Store ticket prices

public:
	void addtickets(int i);
	void displaytickets(int i);
	double calculateTicketPrice(int i);
	void writeticktofile(ofstream& file, int i);

};
class luggage : public Ticket {
protected:
	int no_ofluggages;
	int luggageid[10];
public:
	void luggagedetails(int i);
	void writelugtofile(ofstream& file, int i);
};
class Noticeboard {
public:
	void details();
	void writenottofile(ofstream& file);
};
class Boardingandcheck_in : public luggage {
	int choice1;
public:
	void check_in();
	void boardingpassgeneration(int i);
	void writeboard_tofile(ofstream& file , int i);
};

