#include "User.h"
#include <iostream>
using namespace std;
User::User() {
    name = "";
    gender = "";
    age = 0;
    weight = 0;
    height = 0;
}
User::User(string name, string gender, int age, double weight, double height) {
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->weight = weight;
    this->height = height;
}
string User::getName() const {
    return name;
}
string User::getGender() const {
    return gender;
}
int User::getAge() const {
    return age;
}
double User::getWeight() const {
    return weight;
}
double User::getHeight() const {
    return height;
}
void User::setName(string name) {
    this->name = name;
}
void User::setGender(string gender) {
    this->gender = gender;
}
void User::setAge(int age) {
    this->age = age;
}
void User::setWeight(double weight) {
    this->weight = weight;
}
void User::setHeight(double height) {
    this->height = height;
}
void User::addWorkout(Workout workout) {
    workouts.push_back(workout);
}
void User::removeWorkout(int index) {
    if (index >= 0 && index < workouts.size()) {
        workouts.erase(workouts.begin() + index);
        cout << "Workout removed successfully." << endl;
    } else {
        cout << "Invalid workout index." << endl;
    }
}
Workout* User::getWorkout(int index) {
    if (index >= 0 && index < workouts.size()) {
        return &workouts[index];
    }
    return nullptr;
}
int User::getWorkoutCount() const {
    return workouts.size();
}
void User::displayWorkouts() const {
    if (workouts.empty()) {
        cout << "No workouts added yet." << endl;
        return;
    }
    for (int i = 0; i < workouts.size(); i++) {
        cout << endl;
        cout << "Workout #" << i + 1 << endl;
        workouts[i].displayWorkout();
    }
}
void User::addGoal(Goal goal) {
    goals.push_back(goal);
}
Goal* User::getGoal(int index) {
    if (index >= 0 && index < (int)goals.size()) {
        return &goals[index];
    }

    return nullptr;
}

int User::getGoalCount() const {
    return goals.size();
}
void User::displayGoals() const {
    if (goals.empty()) {
        cout << "No goals added yet." << endl;
        return;
    }
    for (int i = 0; i < goals.size(); i++) {
        cout << endl;
        cout << "Goal #" << i + 1 << endl;
        goals[i].displayGoal();
    }
}
void User::addPersonalRecord(PersonalRecord record) {
    personalRecords.push_back(record);
}
PersonalRecord* User::getPersonalRecord(int index) {
    if (index >= 0 && index < (int)personalRecords.size()) {
        return &personalRecords[index];
    }

    return nullptr;
}

int User::getPersonalRecordCount() const {
    return personalRecords.size();
}
void User::displayPersonalRecords() const {
    if (personalRecords.empty()) {
        cout << "No personal records added yet." << endl;
        return;
    }
    for (int i = 0; i < personalRecords.size(); i++) {
        cout << endl;
        cout << "Personal Record #" << i + 1 << endl;
        personalRecords[i].displayRecord();
    }
}
void User::displayProfile() const {
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Height: " << height << " cm" << endl;
}

void User::clearData() {
    workouts.clear();
    goals.clear();
    personalRecords.clear();

    name = "";
    gender = "";
    age = 0;
    weight = 0;
    height = 0;
}