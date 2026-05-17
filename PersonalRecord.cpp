#include "PersonalRecord.h"
#include <iostream>
using namespace std;
PersonalRecord::PersonalRecord() {
    exerciseName = "";
    value = 0;
    unit = "";
    dateAchieved = "";
}
PersonalRecord::PersonalRecord(string exerciseName, double value, string unit, string dateAchieved) {
    this->exerciseName = exerciseName;
    this->value = value;
    this->unit = unit;
    this->dateAchieved = dateAchieved;
}
string PersonalRecord::getExerciseName() const {
    return exerciseName;
}
double PersonalRecord::getValue() const {
    return value;
}
string PersonalRecord::getUnit() const {
    return unit;
}
string PersonalRecord::getDateAchieved() const {
    return dateAchieved;
}
void PersonalRecord::setExerciseName(string exerciseName) {
    this->exerciseName = exerciseName;
}
void PersonalRecord::setValue(double value) {
    this->value = value;
}
void PersonalRecord::setUnit(string unit) {
    this->unit = unit;
}
void PersonalRecord::setDateAchieved(string dateAchieved) {
    this->dateAchieved = dateAchieved;
}
void PersonalRecord::displayRecord() const {
    cout << "Exercise: " << exerciseName << endl;
    cout << "Record: " << value << " " << unit << endl;
    cout << "Date achieved: " << dateAchieved << endl;
}