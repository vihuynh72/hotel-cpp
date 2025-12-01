#include <iostream>
#include <limits>
#include "UI.h"

using namespace std;

void displayMenu() {
    cout << "\nHotel Reservation Desk" << endl;
    cout << "----------------------" << endl;
    cout << "1. View Room Status" << endl;
    cout << "2. Reserve a Room" << endl;
    cout << "3. View Daily Summary" << endl;
    cout << "4. Save Data" << endl;
    cout << "5. Change Date" << endl;
    cout << "6. Exit" << endl;
    cout << "Select an option: ";
}

int readIntInput() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume newline
    return value;
}

string readStringInput() {
    string value;
    getline(cin, value);
    return value;
}
