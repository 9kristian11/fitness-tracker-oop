#ifndef PERSONAL_RECORD_H
#define PERSONAL_RECORD_H

#include <string>
using namespace std;
class PersonalRecord {
private:
    string exerciseName;
    double value;
    string unit;
    string dateAchieved;
public:
    PersonalRecord();
    PersonalRecord(string exerciseName, double value, string unit, string dateAchieved);

    string getExerciseName() const;
    double getValue() const;
    string getUnit() const;
    string getDateAchieved() const;

    void setExerciseName(string exerciseName);
    void setValue(double value);
    void setUnit(string unit);
    void setDateAchieved(string dateAchieved);

    void displayRecord() const;
};

#endif