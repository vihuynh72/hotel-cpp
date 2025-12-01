#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

class Room {
protected:
    int roomNumber;
    std::string type;
    double rate;
    std::string guestName;
    bool occupied;

public:
    Room(int number, std::string roomType, double nightlyRate) 
        : roomNumber(number), type(roomType), rate(nightlyRate), guestName(""), occupied(false) {}

    virtual ~Room() {}

    int getRoomNumber() const { return roomNumber; }
    std::string getType() const { return type; }
    double getRate() const { return rate; }
    bool isOccupied() const { return occupied; }
    std::string getGuestName() const { return guestName; }

    void reserve(const std::string& guest) {
        guestName = guest;
        occupied = true;
    }

    void checkout() {
        guestName = "";
        occupied = false;
    }

    // Friend class to allow HotelInventory to manage rooms directly if needed
    friend class HotelInventory;
};

class StandardCourtyard : public Room {
public:
    StandardCourtyard(int number) : Room(number, "Standard - Courtyard", 125.0) {}
};

class StandardScenic : public Room {
public:
    StandardScenic(int number) : Room(number, "Standard - Scenic", 145.0) {}
};

class DeluxeSuite : public Room {
public:
    DeluxeSuite(int number) : Room(number, "Deluxe Suite", 350.0) {}
};

class Penthouse : public Room {
public:
    Penthouse(int number) : Room(number, "Penthouse", 1135.0) {}
};

#endif // ROOM_H
