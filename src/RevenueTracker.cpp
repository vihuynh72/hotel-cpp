#include "RevenueTracker.h"

#include <fstream>

RevenueTracker::RevenueTracker(const std::string& storagePath)
    : revenueFilePath(storagePath), dailyRevenue(0.0), cumulativeRevenue(0.0) {
    loadFromFile();
}

void RevenueTracker::loadFromFile() {
    // Pseudocode reminder:
    // 1. Try to open the file.
    // 2. If it exists, read the stored total into cumulativeRevenue.
    // 3. Otherwise default to zero and continue.
    std::ifstream inputFile(revenueFilePath.c_str());
    if (inputFile) {
        inputFile >> cumulativeRevenue;
    } else {
        cumulativeRevenue = 0.0;
        // FUTURE: Consider logging that the file was missing for auditing.
    }
}

void RevenueTracker::recordReservation(double amount) {
    dailyRevenue += amount;
    cumulativeRevenue += amount;
}

double RevenueTracker::getDailyRevenue() const {
    return dailyRevenue;
}

double RevenueTracker::getCumulativeRevenue() const {
    return cumulativeRevenue;
}

void RevenueTracker::save() const {
    // Pseudocode reminder:
    // 1. Open the file for output (truncating old data).
    // 2. Write the cumulative revenue value.
    // 3. Close file automatically when ofstream goes out of scope.
    std::ofstream outputFile(revenueFilePath.c_str());
    if (outputFile) {
        outputFile << cumulativeRevenue;
    }
    // FUTURE: Add error handling/reporting if writing fails.
}
