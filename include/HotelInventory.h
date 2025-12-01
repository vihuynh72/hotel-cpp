#ifndef HOTELINVENTORY_H
#define HOTELINVENTORY_H

#include <vector>
#include <string>
#include "Room.h"

class HotelInventory {
public:
    HotelInventory();
    ~HotelInventory();

    // Initialize rooms for a new day or load from file
    void setDate(std::string date);

    // Display status of all rooms
    void displayStatus();

    // Reserve a specific room
    bool reserveRoom(int roomNumber, std::string guestName);

    // Check out a room
    bool checkoutRoom(int roomNumber);

    // Save current data to file
    void saveToFile();

    // Delete the data file for the current date
    void deleteDataFile();

    // Get room by number
    Room* getRoom(int roomNumber);

    // Display totals/summary
    void displaySummary();

private:
    std::vector<Room*> rooms;
    std::string currentDate;

    void initializeRooms();
    void loadFromFile();
    void clearReservations();
};

#endif // HOTELINVENTORY_H
