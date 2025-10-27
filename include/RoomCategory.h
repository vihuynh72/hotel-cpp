#ifndef ROOMCATEGORY_H
#define ROOMCATEGORY_H

#include <string>

// RoomCategory holds basic facts about a room offering.
// Keeping this lightweight makes it easier to extend with
// additional metadata later (e.g., amenities, occupancy limits).
struct RoomCategory {
    std::string name;
    std::string description;
    int totalRooms;          // Starting inventory for this category.
    int reservedRooms;       // Tracks how many rooms have been reserved today.
    double nightlyRate;      // Price per night for a single room.

    // Helper to compute current availability. Returning an int
    int getAvailableRooms() const;
};

#endif // ROOMCATEGORY_H