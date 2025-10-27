#ifndef REVENUETRACKER_H
#define REVENUETRACKER_H

#include <string>

// RevenueTracker encapsulates how we keep revenue totals for the day and
// persist cumulative earnings to disk. Storing file paths centrally makes
// it easier to swap out the storage layer later (database, API, etc.).
class RevenueTracker {
public:
    explicit RevenueTracker(const std::string& storagePath);

    // Adds the reservation's revenue to both today's and the cumulative totals.
    void recordReservation(double amount);

    // These getters give the menu direct access to the numbers it must display.
    double getDailyRevenue() const;
    double getCumulativeRevenue() const;

    // Persists the cumulative total to disk. Call this before exiting.
    void save() const;

private:
    std::string revenueFilePath;
    double dailyRevenue;
    double cumulativeRevenue;

    void loadFromFile(); // Reads persisted totals when the program starts.
};

#endif // REVENUETRACKER_H
