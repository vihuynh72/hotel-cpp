#include <iostream>

#include "UI.h"
#include "HotelInventory.h"

using namespace std;

int main() {
    HotelInventory inventory;

    bool running = true;
    while (running) {
        displayMenu();
        int choice = readIntInput();

        switch (choice) {
        case 1:
            inventory.displayInventory();
            break;
        case 2: {
            inventory.displayInventory();
            cout << "\nEnter the number of the category to reserve: ";
            int selection = readIntInput();
            int categoryIndex = selection - 1;

            if (!inventory.isValidCategoryIndex(categoryIndex)) {
                cout << "Invalid category selection. Please try again." << endl;
                break;
            }

            const RoomCategory& chosenCategory = inventory.getCategories()[categoryIndex];
            if (inventory.reserveRoomByIndex(categoryIndex)) {
                cout << "Reserved one " << chosenCategory.name
                          << " for $" << chosenCategory.nightlyRate << endl;
            } else {
                cout << "No rooms remaining in that category." << endl;
            }
            break;
        }
        case 3:
            inventory.displayTotals(revenueTracker.getDailyRevenue(),
                                    revenueTracker.getCumulativeRevenue());
            break;
        case 4:
            running = false;
            break;
        default:
            cout << "Please choose a valid option from the menu." << endl;
            break;
        }
    }

    cout <<  "Thank you for using the Hotel Reservation System. Goodbye!" << endl;
    return 0;
}