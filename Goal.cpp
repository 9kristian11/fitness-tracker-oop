#include "Goal.h"
#include <iostream>
using namespace std;
Goal::Goal() {
    description = "";
    targetValue = 0;
    currentValue = 0;
}
Goal::Goal(string description, int targetValue) {
    this->description = description;
    this->targetValue = targetValue;
    currentValue = 0;
}
string Goal::getDescription() const {
    return description;
}
int Goal::getTargetValue() const {
    return targetValue;
}
int Goal::getCurrentValue() const {
    return currentValue;
}
void Goal::setDescription(string description) {
    this->description = description;
}
void Goal::setTargetValue(int targetValue) {
    this->targetValue = targetValue;
}
void Goal::setCurrentValue(int currentValue) {
    this->currentValue = currentValue;
}
bool Goal::isGoalCompleted() const {
    return currentValue >= targetValue;
}
void Goal::displayGoal() const {
    cout << "Goal: " << description << endl;
    cout << "Progress: " << currentValue << "/" << targetValue << endl;
    cout << "Completed: " << (isGoalCompleted() ? "Yes" : "No") << endl;
}