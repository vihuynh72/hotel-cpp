#ifndef HOTELINVENTORY_H
#define HOTELINVENTORY_H

#include <vector>
#include "RoomCategory.h"

// HotelInventory manages the list of room categories for the day.
// Responsibilities: initialize the hotel offerings, reserve rooms, and
// report on current status.
class HotelInventory {
public:
    HotelInventory();

    // Presents all room categories and their remaining counts.
    void displayInventory() const;

    // Attempts to reserve a single room in the category specified by index.
    // Returns true if successful, false if no rooms remain.
    bool reserveRoomByIndex(int categoryIndex);

    // Shows a summary suitable for the manager's daily report.
    void displayTotals(double dailyRevenue, double cumulativeRevenue) const;

    // Helper to validate requested indices before a reservation.
    bool isValidCategoryIndex(int categoryIndex) const;

    // Accessor used by the menu to obtain read-only view of categories.
    const std::vector<RoomCategory>& getCategories() const;

private:
    std::vector<RoomCategory> categories;

    void initializeInventory(); // Sets up the starting counts and rates.
};

#endif // HOTELINVENTORY_H
