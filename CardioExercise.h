#ifndef CARDIO_EXERCISE_H
#define CARDIO_EXERCISE_H

#include "Exercise.h"

class CardioExercise : public Exercise {
private:
    int duration;
    double distance;
public:
    CardioExercise();
    CardioExercise(string name, int duration, double distance);

    int getDuration() const;
    double getDistance() const;

    void setDuration(int duration);
    void setDistance(double distance);

    void display() const override;
};
#endif