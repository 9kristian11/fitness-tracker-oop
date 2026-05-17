#ifndef STRENGTH_EXERCISE_H
#define STRENGTH_EXERCISE_H

#include "Exercise.h"

class StrengthExercise : public Exercise {
public:
    StrengthExercise();
    StrengthExercise(string name, int sets, int reps, double weight);

    void display() const override;
};

#endif