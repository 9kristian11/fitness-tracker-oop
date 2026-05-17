#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "User.h"
void manageUserProfile(User& user);
void manageWorkouts(User& user);
void manageExercises(Workout& workout);
void workoutHistory(const User& user);
#endif