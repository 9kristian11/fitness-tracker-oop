#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <vector>
#include "Exercise.h"
using namespace std;
class Workout {
private:
    string date;
    string description;
    bool isCompleted;
    vector<Exercise*> exercises;
public:
    Workout();
    Workout(string date, string description);

    Workout(const Workout& other);
    Workout& operator=(const Workout& other);

    ~Workout();

    string getDate() const;
    string getDescription() const;
    bool getIsCompleted() const;

    void setDate(string date);
    void setDescription(string description);
    void setIsCompleted(bool isCompleted);

    void addExercise(Exercise* exercise);
    void removeExercise(int index);
    Exercise* getExercise(int index);
    int getExerciseCount() const;
    void displayExercises() const;
    void displayWorkout() const;
};
#endif