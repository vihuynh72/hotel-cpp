#include <iostream>
#include <limits>
#include <iomanip>
#include "UI.h"

using namespace std;

void displayMenu(string date) {
    cout << "\n";
    cout << "  __________________________________________________ " << endl;
    cout << " |                                                  |" << endl;
    cout << " |           HOTEL RESERVATION SYSTEM               |" << endl;
    cout << " |__________________________________________________|" << endl;
    cout << " |                                                  |" << endl;
    cout << " |  CURRENT DATE: " << left << setw(34) << date << "|" << endl;
    cout << " |__________________________________________________|" << endl;
    cout << " |                                                  |" << endl;
    cout << " |  1. [ VIEW ]   Room Status Dashboard             |" << endl;
    cout << " |  2. [ BOOK ]   Make a Reservation                |" << endl;
    cout << " |  3. [ INFO ]   Daily Financial Report            |" << endl;
    cout << " |  4. [ SAVE ]   Save Current Data                 |" << endl;
    cout << " |  5. [ DATE ]   Change Date (Auto-Save)           |" << endl;
    cout << " |  6. [ EXIT ]   Exit System                       |" << endl;
    cout << " |__________________________________________________|" << endl;
    cout << "\n  >> Select an option: ";
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
