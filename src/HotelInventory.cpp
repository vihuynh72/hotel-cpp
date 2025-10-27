#include "HotelInventory.h"

#include <iostream>
#include <iomanip>

HotelInventory::HotelInventory() {
    initializeInventory();
}

void HotelInventory::initializeInventory() {
    // For now, hardcode the room categories. Future versions could load from a config file or database.
}

void HotelInventory::displayInventory() const {
    std::cout << "\nCurrent Room Inventory" << std::endl;
    std::cout << "----------------------" << std::endl;

    for (std::size_t i = 0; i < categories.size(); ++i) {
        
    }
}

bool HotelInventory::reserveRoomByIndex(int categoryIndex) {
    if (!isValidCategoryIndex(categoryIndex)) {
        return false;
    }

    RoomCategory& category = categories[categoryIndex];
    if (category.getAvailableRooms() <= 0) {
        return false; // No rooms left in this category.
    }

    category.reservedRooms += 1; // Single-night stay per requirements.
    return true;
}

void HotelInventory::displayTotals(double dailyRevenue, double cumulativeRevenue) const {
   
}

bool HotelInventory::isValidCategoryIndex(int categoryIndex) const {
    return categoryIndex >= 0 && static_cast<std::size_t>(categoryIndex) < categories.size();
}

const std::vector<RoomCategory>& HotelInventory::getCategories() const {
    return categories;
}