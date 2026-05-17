#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
using namespace std;
class Exercise{
    protected:
    string name;
    int sets;
    int reps;
    double weight;
    public:
    Exercise();
    Exercise(string name, int sets, int reps, double weight);
    virtual ~Exercise();
    string getName() const;
    int getSets() const;
    int getReps() const;
    double getWeight() const;
    void setName(string name);
    void setSets(int sets);
    void setReps(int reps); 
    void setWeight(double weight);
    virtual void display() const=0;
};
#endif

