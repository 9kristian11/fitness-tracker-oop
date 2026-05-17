#ifndef STATISTICS_MANAGER_H
#define STATISTICS_MANAGER_H

#include "User.h"
class StatisticsManager {
public:
    StatisticsManager();
    void workoutHistory(const User& user) const;
    void monthlyStats(const User& user) const;
    void inactivityReminder(const User& user) const;
};
#endif