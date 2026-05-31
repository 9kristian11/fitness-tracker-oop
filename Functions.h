#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "User.h"
void manageUserProfile(User& user);
void manageWorkouts(User& user);
void manageExercises(Workout& workout);
void workoutHistory(const User& user);

void trackPR(User& user);
void monthlyStats(User& user);
void manageGoals(User& user);
void inactivityReminder(User& user);
#endif