#ifndef HOTELINVENTORY_H
#define HOTELINVENTORY_H

#include <vector>
#include "RoomCategory.h"

class HotelInventory {
public:
    HotelInventory();

    // Presents all room categories and their remaining counts
    void displayInventory();

    // Reserve a single room in the category specified by index. Returns true if successful, false if no rooms remain.
    bool reserveRoomByIndex(int categoryIndex);

    // Shows a summary suitable for the manager's daily report.
    void displayTotals(double dailyRevenue, double cumulativeRevenue);

    // Helper to validate requested indices before a reservation.
    bool isValidCategoryIndex(int categoryIndex) const;

    // Accessor used by the menu to obtain read-only view of categories.
    const std::vector<RoomCategory>& getCategories() const;

private:
    std::vector<RoomCategory> categories;

    void initializeInventory(); // Sets up the starting counts and rates.
};

#endif // HOTELINVENTORY_H