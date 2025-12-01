#include "RoomCategory.h"

int RoomCategory::getAvailableRooms() const {
    return totalRooms - reservedRooms;
}