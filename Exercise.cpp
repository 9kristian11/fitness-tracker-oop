#include "Exercise.h"
Exercise::Exercise() {
    name = "";
    sets = 0;
    reps = 0;
    weight = 0;
}
Exercise::Exercise(string name, int sets, int reps, double weight) {
    this->name = name;
    this->sets = sets;
    this->reps = reps;
    this->weight = weight;
}
Exercise::~Exercise() {
}
string Exercise::getName() const {
    return name;
}
int Exercise::getSets() const {
    return sets;
}
int Exercise::getReps() const {
    return reps;
}
double Exercise::getWeight() const {
    return weight;
}
void Exercise::setName(string name) {
    this->name = name;
}
void Exercise::setSets(int sets) {
    this->sets = sets;
}
void Exercise::setReps(int reps) {
    this->reps = reps;
}
void Exercise::setWeight(double weight) {
    this->weight = weight;
}