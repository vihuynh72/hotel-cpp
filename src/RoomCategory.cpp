#include "RoomCategory.h"

int RoomCategory::getAvailableRooms() const {
    // Availability is simply the starting inventory minus today's reservations.
    // Future enhancements could read real-time occupancy data here instead.
    return totalRooms - reservedRooms;
}
