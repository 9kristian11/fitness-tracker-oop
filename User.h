#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Workout.h"
#include "Goal.h"
#include "PersonalRecord.h"
using namespace std;
class User {
private:
    string name;
    string gender;
    int age;
    double weight;
    double height;
    vector<Workout> workouts;
    vector<Goal> goals;
    vector<PersonalRecord> personalRecords;
public:
    User();
    User(string name, string gender, int age, double weight, double height);

    string getName() const;
    string getGender() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

    void setName(string name);
    void setGender(string gender);
    void setAge(int age);
    void setWeight(double weight);
    void setHeight(double height);

    void addWorkout(Workout workout);
    void removeWorkout(int index);
    Workout* getWorkout(int index);
    int getWorkoutCount() const;
    void displayWorkouts() const;

    void addGoal(Goal goal);
    Goal* getGoal(int index);
    int getGoalCount() const;
    void displayGoals() const;

    void addPersonalRecord(PersonalRecord record);
    PersonalRecord* getPersonalRecord(int index);
    int getPersonalRecordCount() const;
    void displayPersonalRecords() const;

    void displayProfile() const;

    void clearData();

};
#endif