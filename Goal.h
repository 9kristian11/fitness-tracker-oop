#ifndef GOAL_H
#define GOAL_H

#include <string>
using namespace std;
class Goal {
private:
    string description;
    int targetValue;
    int currentValue;
public:
    Goal();
    Goal(string description, int targetValue);

    string getDescription() const;
    int getTargetValue() const;
    int getCurrentValue() const;

    void setDescription(string description);
    void setTargetValue(int targetValue);
    void setCurrentValue(int currentValue);

    bool isGoalCompleted() const;
    void displayGoal() const;
};
#endif