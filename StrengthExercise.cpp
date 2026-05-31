#include "StrengthExercise.h"
#include <iostream>
using namespace std;
StrengthExercise::StrengthExercise() : Exercise() {
}
StrengthExercise::StrengthExercise(string name, int sets, int reps, double weight)
    : Exercise(name, sets, reps, weight) {
}
void StrengthExercise::display() const {
    cout << "Strength Exercise: " << name << endl;
    cout << "Sets: " << sets << endl;
    cout << "Reps: " << reps << endl;
    cout << "Weight: " << weight << " kg" << endl;
    
}

Exercise* StrengthExercise::clone() const {
    return new StrengthExercise(name, sets, reps, weight);
}