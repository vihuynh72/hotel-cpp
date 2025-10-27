#ifndef ROOMCATEGORY_H
#define ROOMCATEGORY_H

#include <string>

// RoomCategory holds basic facts about a room offering.
// Keeping this lightweight makes it easier to extend with
// additional metadata later (e.g., amenities, occupancy limits).
struct RoomCategory {
    std::string name;        // Human-friendly label for the category.
    std::string description; // Additional notes that can clarify the view or location.
    int totalRooms;          // Starting inventory for this category.
    int reservedRooms;       // Tracks how many rooms have been reserved today.
    double nightlyRate;      // Price per night for a single room.

    // Helper to compute current availability. Returning an int keeps
    // the interface simple for introductory C++ chapters.
    int getAvailableRooms() const;
};

#endif // ROOMCATEGORY_H
