#include "StatisticsManager.h"
#include <iostream>
using namespace std;
StatisticsManager::StatisticsManager() {
}
void StatisticsManager::workoutHistory(const User& user) const {
    cout << endl;
    cout << "Workout History" << endl;
    cout << "---------------" << endl;
    user.displayWorkouts();
}
void StatisticsManager::monthlyStats(const User& user) const {
    cout << endl;
    cout << "Monthly Statistics" << endl;
    cout << "------------------" << endl;
    cout << "This simple version shows all workouts for the month." << endl;
    user.displayWorkouts();
}
void StatisticsManager::inactivityReminder(const User& user) const {
    cout << endl;
    cout << "Inactivity Reminder" << endl;
    cout << "-------------------" << endl;
    cout << "Remember to stay consistent with your workouts!Keep grinding!" << endl;
}