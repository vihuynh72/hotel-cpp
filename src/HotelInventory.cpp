#include "HotelInventory.h"

#include <iostream>
#include <iomanip>

using namespace std;

HotelInventory::HotelInventory() {
    initializeInventory();
}

void HotelInventory::initializeInventory() {
    // For now, hardcode the room categories. Future versions could load from a config file or database.

    categories.clear();

    RoomCategory standardCourtyard;
    standardCourtyard.name = "Standard - Courtyard";
    standardCourtyard.description = "Courtyard view";
    standardCourtyard.totalRooms = 70;
    standardCourtyard.reservedRooms = 0;
    standardCourtyard.nightlyRate = 125.0;
    categories.push_back(standardCourtyard);

    RoomCategory standardScenic;
    standardScenic.name = "Standard - Scenic";
    standardScenic.description = "Scenic view";
    standardScenic.totalRooms = 35;
    standardScenic.reservedRooms = 0;
    standardScenic.nightlyRate = 145.0;
    categories.push_back(standardScenic);

    RoomCategory deluxeSuite;
    deluxeSuite.name = "Deluxe Suite";
    deluxeSuite.description = "Spacious suite";
    deluxeSuite.totalRooms = 15;
    deluxeSuite.reservedRooms = 0;
    deluxeSuite.nightlyRate = 350.0;
    categories.push_back(deluxeSuite);

    RoomCategory penthouse;
    penthouse.name = "Penthouse";
    penthouse.description = "Top-level luxury";
    penthouse.totalRooms = 2;
    penthouse.reservedRooms = 0;
    penthouse.nightlyRate = 1135.0;
    categories.push_back(penthouse);
}

void HotelInventory::displayInventory() const {
    cout << "\nCurrent Room Inventory" << std::endl;
    cout << "----------------------" << std::endl;

    for (size_t i = 0; i < categories.size(); ++i) {
         const RoomCategory& category = categories[i];

        cout << (i + 1) << ". " << category.name << " (" << category.description << ")" << endl;
        cout << "   Rate: $" << fixed << setprecision(2) << category.nightlyRate << " per night" << endl;
        cout << "   Available: " << category.getAvailableRooms() << " of " << category.totalRooms << " rooms" << endl;
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