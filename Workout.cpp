#include "Workout.h"
#include <iostream>
using namespace std;
Workout::Workout() {
    date = "";
    description = "";
    isCompleted = false;
}
Workout::Workout(string date, string description) {
    this->date = date;
    this->description = description;
    isCompleted = false;
}

Workout::Workout(const Workout& other) {
    date = other.date;
    description = other.description;
    isCompleted = other.isCompleted;

    for (int i = 0; i < other.exercises.size(); i++) {
        exercises.push_back(other.exercises[i]->clone());
    }
}

Workout& Workout::operator=(const Workout& other) {
    if (this != &other) {
        for (int i = 0; i < exercises.size(); i++) {
            delete exercises[i];
        }

        exercises.clear();

        date = other.date;
        description = other.description;
        isCompleted = other.isCompleted;

        for (int i = 0; i < other.exercises.size(); i++) {
            exercises.push_back(other.exercises[i]->clone());
        }
    }

    return *this;
}

Workout::~Workout() {
    for (int i = 0; i < exercises.size(); i++) {
        delete exercises[i];
    }
    exercises.clear();
}
string Workout::getDate() const {
    return date;
}
string Workout::getDescription() const {
    return description;
}
bool Workout::getIsCompleted() const {
    return isCompleted;
}
void Workout::setDate(string date) {
    this->date = date;
}
void Workout::setDescription(string description) {
    this->description = description;
}
void Workout::setIsCompleted(bool isCompleted) {
    this->isCompleted = isCompleted;
}
void Workout::addExercise(Exercise* exercise) {
    exercises.push_back(exercise);
}
void Workout::removeExercise(int index) {
    if (index >= 0 && index < exercises.size()) {
        delete exercises[index];
        exercises.erase(exercises.begin() + index);
        cout << "Exercise removed successfully." << endl;
    } else {
        cout << "Invalid exercise index." << endl;
    }
}
Exercise* Workout::getExercise(int index) {
    if (index >= 0 && index < exercises.size()) {
        return exercises[index];
    }

    return nullptr;
}
int Workout::getExerciseCount() const {
    return exercises.size();
}
void Workout::displayExercises() const {
    if (exercises.empty()) {
        cout << "No exercises in this workout." << endl;
        return;
    }
    for (int i = 0; i < exercises.size(); i++) {
        cout << endl;
        cout << "Exercise #" << i + 1 << endl;
        exercises[i]->display();
    }
}
void Workout::displayWorkout() const {
    cout << "Date: " << date << endl;
    cout << "Description: " << description << endl;
    cout << "Completed: " << (isCompleted ? "Yes" : "No") << endl;
    cout << "Exercises: " << exercises.size() << endl;
}