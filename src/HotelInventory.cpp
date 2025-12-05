#include "HotelInventory.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

HotelInventory::HotelInventory() {
    if (!fs::exists("data")) {
        fs::create_directory("data");
    }
    initializeRooms();
}

HotelInventory::~HotelInventory() {
    for (Room* room : rooms) {
        delete room;
    }
    rooms.clear();
}

void HotelInventory::initializeRooms() {
    // Standard Rooms, Courtyard - 70 - 25 a night - Rooms 101 thru 170
    for (int i = 101; i <= 170; ++i) {
        rooms.push_back(new StandardCourtyard(i));
    }

    // Standard Room, Scenic - 35 - 45 a night - Rooms 201 thru 235
    for (int i = 201; i <= 235; ++i) {
        rooms.push_back(new StandardScenic(i));
    }

    // Deluxe Suite - 15 - 50 a night - Rooms 236 thru 250
    for (int i = 236; i <= 250; ++i) {
        rooms.push_back(new DeluxeSuite(i));
    }

    // Penthouse - 2 - 135 a night - Rooms 301 and 302
    for (int i = 301; i <= 302; ++i) {
        rooms.push_back(new Penthouse(i));
    }
}

void HotelInventory::setDate(string date) {
    currentDate = date;
    // Try to load from file
    ifstream inFile("data/" + currentDate + ".txt");
    if (inFile.good()) {
        inFile.close();
        loadFromFile();
    } else {
        clearReservations();
        cout << "Starting new day: " << currentDate << endl;
    }
}

void HotelInventory::clearReservations() {
    for (Room* room : rooms) {
        room->checkout();
    }
}

void HotelInventory::saveToFile() {
    if (currentDate.empty()) return;

    ofstream outFile("data/" + currentDate + ".txt");
    if (!outFile) {
        cerr << "Error opening file for writing: data/" << currentDate << ".txt" << endl;
        return;
    }

    for (Room* room : rooms) {
        if (room->isOccupied()) {
            outFile << room->getRoomNumber() << " " << room->getGuestName() << endl;
        }
    }
    outFile.close();
    cout << "Data saved to data/" << currentDate << ".txt" << endl;
}

void HotelInventory::deleteDataFile() {
    string filename = "data/" + currentDate + ".txt";
    if (fs::exists(filename)) {
        if (fs::remove(filename)) {
            cout << ">> SUCCESS: Data file for " << currentDate << " has been deleted." << endl;
        } else {
            cout << ">> ERROR: Could not delete data file." << endl;
        }
    } else {
        cout << ">> INFO: No saved data file found. Session data discarded." << endl;
    }
}

void HotelInventory::loadFromFile() {
    ifstream inFile("data/" + currentDate + ".txt");
    if (!inFile) {
        cerr << "Error opening file for reading: data/" << currentDate << ".txt" << endl;
        return;
    }

    clearReservations(); // Clear current state before loading

    int roomNum;
    string guestName;
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        ss >> roomNum;
        // The rest of the line is the guest name (might contain spaces)
        getline(ss, guestName);
        
        // Trim leading whitespace from guestName
        size_t first = guestName.find_first_not_of(' ');
        if (string::npos != first) {
            guestName = guestName.substr(first);
        }

        Room* room = getRoom(roomNum);
        if (room) {
            room->reserve(guestName);
        }
    }
    inFile.close();
    cout << "Data loaded from data/" << currentDate << ".txt" << endl;
}

Room* HotelInventory::getRoom(int roomNumber) {
    for (Room* room : rooms) {
        if (room->getRoomNumber() == roomNumber) {
            return room;
        }
    }
    return nullptr;
}

bool HotelInventory::reserveRoom(int roomNumber, string guestName) {
    Room* room = getRoom(roomNumber);
    if (room && !room->isOccupied()) {
        room->reserve(guestName);
        return true;
    }
    return false;
}

bool HotelInventory::checkoutRoom(int roomNumber) {
    Room* room = getRoom(roomNumber);
    if (room && room->isOccupied()) {
        room->checkout();
        return true;
    }
    return false;
}

void HotelInventory::displayStatus() {
    cout << "\n==================================================================================" << endl;
    cout << "                            HOTEL OCCUPANCY DASHBOARD: " << currentDate << endl;
    cout << "==================================================================================" << endl;
    
    // 1. Standard Courtyard (101-170)
    cout << "\n [ STANDARD COURTYARD ($125) ]" << endl;
    cout << " ---------------------------------------------------------------------------------" << endl;
    int count = 0;
    for (Room* room : rooms) {
        if (room->getRoomNumber() >= 101 && room->getRoomNumber() <= 170) {
            string status = room->isOccupied() ? room->getGuestName() : ".";
            if (status.length() > 9) status = status.substr(0, 8) + ".";
            
            cout << " " << setw(3) << room->getRoomNumber() << ": " << left << setw(10) << status;
            count++;
            if (count % 5 == 0) cout << endl;
        }
    }
    if (count % 5 != 0) cout << endl;

    // 2. Standard Scenic (201-235)
    cout << "\n [ STANDARD SCENIC ($145) ]" << endl;
    cout << " ---------------------------------------------------------------------------------" << endl;
    count = 0;
    for (Room* room : rooms) {
        if (room->getRoomNumber() >= 201 && room->getRoomNumber() <= 235) {
            string status = room->isOccupied() ? room->getGuestName() : ".";
            if (status.length() > 9) status = status.substr(0, 8) + ".";
            
            cout << " " << setw(3) << room->getRoomNumber() << ": " << left << setw(10) << status;
            count++;
            if (count % 5 == 0) cout << endl;
        }
    }
    if (count % 5 != 0) cout << endl;

    // 3. Deluxe Suite (236-250)
    cout << "\n [ DELUXE SUITE ($350) ]" << endl;
    cout << " ---------------------------------------------------------------------------------" << endl;
    count = 0;
    for (Room* room : rooms) {
        if (room->getRoomNumber() >= 236 && room->getRoomNumber() <= 250) {
            string status = room->isOccupied() ? room->getGuestName() : ".";
            if (status.length() > 9) status = status.substr(0, 8) + ".";
            
            cout << " " << setw(3) << room->getRoomNumber() << ": " << left << setw(10) << status;
            count++;
            if (count % 5 == 0) cout << endl;
        }
    }
    if (count % 5 != 0) cout << endl;

    // 4. Penthouse (301-302)
    cout << "\n [ PENTHOUSE ($1135) ]" << endl;
    cout << " ---------------------------------------------------------------------------------" << endl;
    count = 0;
    for (Room* room : rooms) {
        if (room->getRoomNumber() >= 301 && room->getRoomNumber() <= 302) {
            string status = room->isOccupied() ? room->getGuestName() : ".";
            
            cout << " " << setw(3) << room->getRoomNumber() << ": " << left << setw(15) << status;
            count++;
        }
    }
    cout << endl;
    cout << "==================================================================================" << endl;
    cout << " Key: '.' = Available, [Name] = Occupied" << endl;
}

void HotelInventory::displaySummary() {
    int occupied = 0;
    double revenue = 0.0;
    
    for (Room* room : rooms) {
        if (room->isOccupied()) {
            occupied++;
            revenue += room->getRate();
        }
    }
    
    cout << "\n========================================" << endl;
    cout << "       DAILY FINANCIAL REPORT           " << endl;
    cout << "========================================" << endl;
    cout << " Date:           " << currentDate << endl;
    cout << "----------------------------------------" << endl;
    cout << " Total Rooms:    " << rooms.size() << endl;
    cout << " Occupied:       " << occupied << " (" << fixed << setprecision(1) << (occupied * 100.0 / rooms.size()) << "%)" << endl;
    cout << " Available:      " << (rooms.size() - occupied) << endl;
    cout << "----------------------------------------" << endl;
    cout << " Total Revenue:  $" << fixed << setprecision(2) << revenue << endl;
    cout << "========================================" << endl;
}
