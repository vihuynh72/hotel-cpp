#include <iostream>
#include <limits>

#include "HotelInventory.h"
#include "RevenueTracker.h"

// Utility function keeps the menu printing logic tidy.
void displayMenu();
// Helper to safely read an integer from the user.
int readIntInput();

int main() {
    HotelInventory inventory;
    RevenueTracker revenueTracker("data/revenue.txt");

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
            std::cout << "\nEnter the number of the category to reserve: ";
            int selection = readIntInput();
            int categoryIndex = selection - 1; // Convert from menu numbering.

            if (!inventory.isValidCategoryIndex(categoryIndex)) {
                std::cout << "Invalid category selection. Please try again." << std::endl;
                break;
            }

            const RoomCategory& chosenCategory = inventory.getCategories()[categoryIndex];
            if (inventory.reserveRoomByIndex(categoryIndex)) {
                revenueTracker.recordReservation(chosenCategory.nightlyRate);
                std::cout << "Reserved one " << chosenCategory.name
                          << " for $" << chosenCategory.nightlyRate << std::endl;
            } else {
                std::cout << "No rooms remaining in that category." << std::endl;
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
            std::cout << "Please choose a valid option from the menu." << std::endl;
            break;
        }
    }

    // Persist totals before shutting down so we can pick up where we left off tomorrow.
    revenueTracker.save();

    std::cout << "Goodbye!" << std::endl;
    return 0;
}

void displayMenu() {
    std::cout << "\nHotel Reservation Desk" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "1. View room inventory" << std::endl;
    std::cout << "2. Reserve a room" << std::endl;
    std::cout << "3. View totals" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Select an option: ";
}

int readIntInput() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid number: ";
    }
    return value;
}
