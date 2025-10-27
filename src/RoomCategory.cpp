#include "RoomCategory.h"

int RoomCategory::getAvailableRooms() const {
    // Availability is simply the starting inventory minus today's reservations.
    return totalRooms - reservedRooms;
}