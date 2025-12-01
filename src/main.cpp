#include <iostream>
#include "UI.h"
#include "HotelInventory.h"

using namespace std;

int main() {
    HotelInventory hotel;
    
    cout << "Welcome to the Hotel Reservation System." << endl;
    cout << "Please enter today's date (e.g., 2023-10-27): ";
    string date = readStringInput();
    hotel.setDate(date);

    bool running = true;
    while (running) {
        displayMenu();
        int choice = readIntInput();

        switch (choice) {
        case 1:
            hotel.displayStatus();
            break;
        case 2: {
            cout << "Enter Room Number to reserve: ";
            int roomNum = readIntInput();
            
            Room* room = hotel.getRoom(roomNum);
            if (room == nullptr) {
                cout << "Invalid Room Number." << endl;
            } else if (room->isOccupied()) {
                cout << "Room " << roomNum << " is already occupied by " << room->getGuestName() << "." << endl;
            } else {
                cout << "Enter Guest Name: ";
                string guestName = readStringInput();
                if (hotel.reserveRoom(roomNum, guestName)) {
                    cout << "Reservation successful for " << guestName << " in Room " << roomNum << "." << endl;
                } else {
                    cout << "Reservation failed." << endl;
                }
            }
            break;
        }
        case 3:
            hotel.displaySummary();
            break;
        case 4:
            hotel.saveToFile();
            break;
        case 5:
            hotel.saveToFile(); // Auto-save before changing date to prevent data loss
            cout << "Enter new date: ";
            date = readStringInput();
            hotel.setDate(date);
            break;
        case 6:
            cout << "Do you want to delete the data file for this date? (y/n): ";
            {
                string response = readStringInput();
                if (response == "y" || response == "Y") {
                    hotel.deleteDataFile();
                } else {
                    hotel.saveToFile();
                }
            }
            running = false;
            break;
        default:
            cout << "Please choose a valid option from the menu." << endl;
            break;
        }
    }

    cout << "Thank you for using the Hotel Reservation System. Goodbye!" << endl;
    return 0;
}
