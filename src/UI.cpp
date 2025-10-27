#include <iostream>

#include "UI.h"

using namespace std;

void displayMenu() {
    cout << "\nHotel Reservation Desk" << endl;
    cout << "----------------------" << endl;
    cout << "1. View room inventory" << endl;
    cout << "2. Reserve a room" << endl;
    cout << "3. View totals" << endl;
    cout << "4. Exit" << endl;
    cout << "Select an option: ";
}

int readIntInput() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cout << "Please enter a valid number: ";
    }
    return value;
}