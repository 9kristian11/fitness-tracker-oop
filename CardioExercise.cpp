#include "CardioExercise.h"
#include <iostream>
using namespace std;
CardioExercise::CardioExercise() : Exercise() {
    duration = 0;
    distance = 0;
}
CardioExercise::CardioExercise(string name, int duration, double distance)
    : Exercise(name, 0, 0, 0) {
    this->duration = duration;
    this->distance = distance;
}
int CardioExercise::getDuration() const {
    return duration;
}
double CardioExercise::getDistance() const {
    return distance;
}
void CardioExercise::setDuration(int duration) {
    this->duration = duration;
}
void CardioExercise::setDistance(double distance) {
    this->distance = distance;
}
void CardioExercise::display() const {
    cout << "Cardio Exercise: " << name << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Distance: " << distance << " km" << endl;
}