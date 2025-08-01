#include<iostream>
#include "Airline.h"
#include<fstream>
// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
int main() {
    Airline airline; // Display the airline details
    Noticeboard n;
    Boardingandcheck_in b;
    int num;
    cout << GREEN<<"\nEnter number of passengers:";
    cin >> num;
    int option;
    for (int i = 0; i < num; i++)
    {
        do {
            cout << BLUE <<"\n\t\t|1. Flight Booking|\n";
            cout << BLUE << "\t\t|2. Luggage Details:|\n";
            cout << BLUE << "\t\t|3. View Noticeboard|\n";
            cout << BLUE << "\t\t|4. Check-in and Boarding|\n";
            cout << BLUE << "\t\t|5. Write To File|\n";
            cout << BLUE << "\t\t|6. Exit|\n";
            cout << BLUE << "\t\tEnter your choice: ";
            cin >> option;
            switch (option) {
            case 1: {

                b.putdetails(i); // Get passenger details
                b.displaypassengerdetails(i);
                b.flights(i); // Select flight and display confirmation
                b.addtickets(i); // Add ticket details
                b.displaytickets(i); // Display ticket details
                break;
            }
            case 2:
            {
                b.luggagedetails(i);  // Get luggage details
                break;
            }
            case 3: {

                n.details(); // Display noticeboard details
                break;
            }
            case 4: {

                b.check_in(); // Perform check-in
                b.boardingpassgeneration(i); // Generate boarding pass
                break;
            }
            case 5: {
                ofstream file("OOP Airline management.txt", ios::app);
                {
                    airline.writeairdetails();
                    b.writepastofile(file, i);
                    b.writeflighttofile(file, i);
                    b.writelugtofile(file, i);
                    b.writeticktofile(file, i);
                    n.writenottofile(file);
                    b.writeboard_tofile(file, i);
                }
                file.close();
                break;

            }
            default:
                cout <<RED<< "\t\tInvalid choice. Please try again.\n";
                break;
            }


        } while (option != 5);

    }
    return 0;
}