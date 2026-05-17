#include "Functions.h"
#include "StrengthExercise.h"
#include <iostream>

using namespace std;
void manageUserProfile(User& user) {
    string name;
    string gender;
    int age;
    double weight;
    double height;
    cout << endl;
    cout << "Manage User Profile" << endl;
    cout << "-------------------" << endl;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter gender: ";
    getline(cin, gender);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter weight: ";
    cin >> weight;
    cout << "Enter height: ";
    cin >> height;
    cin.ignore();
    user.setName(name);
    user.setGender(gender);
    user.setAge(age);
    user.setWeight(weight);
    user.setHeight(height);
    cout << "Profile saved successfully." << endl;
}
void manageWorkouts(User& user) {
    int choice;
    do {
        cout << endl;
        cout << "Manage Workouts" << endl;
        cout << "---------------" << endl;
        cout << "1. Add workout" << endl;
        cout << "2. Edit workout" << endl;
        cout << "3. Delete workout" << endl;
        cout << "4. Manage exercises in workout" << endl;
        cout << "5. Display workouts" << endl;
        cout << "0. Back" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string date;
            string description;
            cout << "Enter workout date: ";
            getline(cin, date);
            cout << "Enter workout description: ";
            getline(cin, description);
            Workout workout(date, description);
            user.addWorkout(workout);
            cout << "Workout added successfully." << endl;
        }
        else if (choice == 2) {
            int index;
            string date;
            string description;
            char completedChoice;
            user.displayWorkouts();
            cout << "Enter workout number to edit: ";
            cin >> index;
            cin.ignore();
            Workout* workout = user.getWorkout(index - 1);
            if (workout != nullptr) {
                cout << "Enter new date: ";
                getline(cin, date);
                cout << "Enter new description: ";
                getline(cin, description);
                cout << "Is workout completed? y/n: ";
                cin >> completedChoice;
                cin.ignore();
                workout->setDate(date);
                workout->setDescription(description);
                workout->setIsCompleted(completedChoice == 'y' || completedChoice == 'Y');
                cout << "Workout edited successfully." << endl;
            }
            else {
                cout << "Invalid workout number." << endl;
            }
        }
        else if (choice == 3) {
            int index;
            user.displayWorkouts();
            cout << "Enter workout number to delete: ";
            cin >> index;
            cin.ignore();
            user.removeWorkout(index - 1);
        }
        else if (choice == 4) {
            int index;
            user.displayWorkouts();
            cout << "Enter workout number: ";
            cin >> index;
            cin.ignore();
            Workout* workout = user.getWorkout(index - 1);
            if (workout != nullptr) {
                manageExercises(*workout);
            }
            else {
                cout << "Invalid workout number." << endl;
            }
        }
        else if (choice == 5) {
            user.displayWorkouts();
        }
    } while (choice != 0);
}
void manageExercises(Workout& workout) {
    int choice;
    do {
        cout << endl;
        cout << "Manage Exercises" << endl;
        cout << "----------------" << endl;
        cout << "1. Add strength exercise" << endl;
        cout << "2. Edit exercise" << endl;
        cout << "3. Remove exercise" << endl;
        cout << "4. Display exercises" << endl;
        cout << "0. Back" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string name;
            int sets;
            int reps;
            double weight;
            cout << "Enter exercise name: ";
            getline(cin, name);
            cout << "Enter sets: ";
            cin >> sets;
            cout << "Enter reps: ";
            cin >> reps;
            cout << "Enter weight: ";
            cin >> weight;
            cin.ignore();
            Exercise* exercise = new StrengthExercise(name, sets, reps, weight);
            workout.addExercise(exercise);
            cout << "Exercise added successfully." << endl;
        }
        else if (choice == 2) {
            int index;
            string name;
            int sets;
            int reps;
            double weight;
            workout.displayExercises();
            cout << "Enter exercise number to edit: ";
            cin >> index;
            cin.ignore();
            Exercise* exercise = workout.getExercise(index - 1);
            if (exercise != nullptr) {
                cout << "Enter new exercise name: ";
                getline(cin, name);
                cout << "Enter new sets: ";
                cin >> sets;
                cout << "Enter new reps: ";
                cin >> reps;
                cout << "Enter new weight: ";
                cin >> weight;
                cin.ignore();
                exercise->setName(name);
                exercise->setSets(sets);
                exercise->setReps(reps);
                exercise->setWeight(weight);
                cout << "Exercise edited successfully." << endl;
            }
            else {
                cout << "Invalid exercise number." << endl;
            }
        }
        else if (choice == 3) {
            int index;
            workout.displayExercises();
            cout << "Enter exercise number to remove: ";
            cin >> index;
            cin.ignore();
            workout.removeExercise(index - 1);
        }
        else if (choice == 4) {
            workout.displayExercises();
        }
    } while (choice != 0);
}
void workoutHistory(const User& user) {
    cout << endl;
    cout << "Workout History" << endl;
    cout << "---------------" << endl;
    user.displayWorkouts();
}