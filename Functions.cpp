#include "Functions.h"
#include "StrengthExercise.h"
#include "PersonalRecord.h"
#include "Goal.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "CardioExercise.h"

#include <iostream>

using namespace std;


void manageUserProfile(User& user, bool& dataLoaded) {
    string name;
    string gender;
    int age;
    double weight;
    double height;

    cout << endl;
    cout << "Manage User Profile" << endl;
    cout << "-------------------" << endl;

    if (dataLoaded == true) {
        char clearChoice;

        cout << "Are you sure you want to clear all user data? y/n: ";
        cin >> clearChoice;
        cin.ignore();

        if (clearChoice == 'y' || clearChoice == 'Y') {
            user.clearData();
            dataLoaded = false;
            cout << "Current loaded user data cleared from the program." << endl;
        }
        else {
            cout << "Returning back to menu." << endl;
            return;
        }
    }

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter gender (male/female): ";
    getline(cin, gender);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter weight (kg): ";
    cin >> weight;

    cout << "Enter height (cm): ";
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
            cout << "Enter workout date(YYYY-MM-DD): ";
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
                cout << "Enter new date(YYYY-MM-DD): ";
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
        cout << "1. Add exercise" << endl;
        cout << "2. Edit exercise" << endl;
        cout << "3. Remove exercise" << endl;
        cout << "4. Display exercises" << endl;
        cout << "0. Back" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int type;

            cout << endl;
            cout << "Choose exercise type" << endl;
            cout << "1. Strength exercise" << endl;
            cout << "2. Cardio exercise" << endl;
            cout << "Choose: ";
            cin >> type;
            cin.ignore();

            if (type == 1) {
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

                cout << "Strength exercise added successfully." << endl;
            }
            else if (type == 2) {
                string name;
                int duration;
                double distance;

                cout << "Enter exercise name: ";
                getline(cin, name);

                cout << "Enter duration in minutes: ";
                cin >> duration;

                cout << "Enter distance in km: ";
                cin >> distance;
                cin.ignore();

                Exercise* exercise = new CardioExercise(name, duration, distance);
                workout.addExercise(exercise);

                cout << "Cardio exercise added successfully." << endl;
            }
            else {
                cout << "Invalid exercise type." << endl;
            }
        }
        else if (choice == 2) {
            int index;

            workout.displayExercises();

            cout << "Enter exercise number to edit: ";
            cin >> index;
            cin.ignore();

            if (workout.getExercise(index - 1) != nullptr) {
                workout.removeExercise(index - 1);

                cout << "Now enter the new exercise data." << endl;

                int type;

                cout << "1. Strength exercise" << endl;
                cout << "2. Cardio exercise" << endl;
                cout << "Choose: ";
                cin >> type;
                cin.ignore();

                if (type == 1) {
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

                    workout.addExercise(new StrengthExercise(name, sets, reps, weight));
                }
                else if (type == 2) {
                    string name;
                    int duration;
                    double distance;

                    cout << "Enter exercise name: ";
                    getline(cin, name);

                    cout << "Enter duration in minutes: ";
                    cin >> duration;

                    cout << "Enter distance in km: ";
                    cin >> distance;
                    cin.ignore();

                    workout.addExercise(new CardioExercise(name, duration, distance));
                }

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

void trackPR(User& user) {
    int choice;

    do {
        cout << endl;
        cout << "Track Personal Records" << endl;
        cout << "----------------------" << endl;
        cout << "1. Add or update personal record" << endl;
        cout << "2. Display personal records" << endl;
        cout << "0. Back" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string exerciseName;
            double value;
            string unit;
            string dateAchieved;

            cout << "Enter exercise name: ";
            getline(cin, exerciseName);

            cout << "Enter record value: ";
            cin >> value;
            cin.ignore();

            cout << "Enter unit, for example kg, km, minutes: ";
            getline(cin, unit);

            cout << "Enter date achieved, for example 2026-05-31: ";
            getline(cin, dateAchieved);

            bool found = false;

            for (int i = 0; i < user.getPersonalRecordCount(); i++) {
                PersonalRecord* record = user.getPersonalRecord(i);

                if (record != nullptr && record->getExerciseName() == exerciseName) {
                    found = true;

                    if (value > record->getValue()) {
                        record->setValue(value);
                        record->setUnit(unit);
                        record->setDateAchieved(dateAchieved);

                        cout << "New personal record saved!" << endl;
                    }
                    else {
                        cout << "This is not better than your current record." << endl;
                    }
                }
            }

            if (!found) {
                PersonalRecord newRecord(exerciseName, value, unit, dateAchieved);
                user.addPersonalRecord(newRecord);

                cout << "Personal record added successfully." << endl;
            }
        }
        else if (choice == 2) {
            user.displayPersonalRecords();
        }

    } while (choice != 0);
}

void monthlyStats(User& user) {
    string month;
    int workoutCount = 0;
    double totalVolume = 0;

    cout << endl;
    cout << "Monthly Statistics" << endl;
    cout << "------------------" << endl;

    cout << "Enter month, for example 2026-05: ";
    getline(cin, month);

    for (int i = 0; i < user.getWorkoutCount(); i++) {
        Workout* workout = user.getWorkout(i);

        if (workout != nullptr) {
            string date = workout->getDate();

            if (date.substr(0, 7) == month) {
                workoutCount++;

                for (int j = 0; j < workout->getExerciseCount(); j++) {
                    Exercise* exercise = workout->getExercise(j);

                    if (exercise != nullptr) {
                        totalVolume += exercise->getSets() * exercise->getReps() * exercise->getWeight();
                    }
                }
            }
        }
    }

    cout << "Workouts this month: " << workoutCount << endl;
    cout << "Total training volume: " << totalVolume << endl;
}

void manageGoals(User& user) {
    int choice;

    do {
        cout << endl;
        cout << "Manage Goals" << endl;
        cout << "------------" << endl;
        cout << "1. Add goal" << endl;
        cout << "2. Update goal progress" << endl;
        cout << "3. Display goals" << endl;
        cout << "0. Back" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string description;
            int targetValue;

            cout << "Enter goal description: ";
            getline(cin, description);

            cout << "Enter target value: ";
            cin >> targetValue;
            cin.ignore();

            Goal goal(description, targetValue);
            user.addGoal(goal);

            cout << "Goal added successfully." << endl;
        }
        else if (choice == 2) {
            int index;
            int currentValue;

            user.displayGoals();

            cout << "Enter goal number to update: ";
            cin >> index;

            cout << "Enter current value: ";
            cin >> currentValue;
            cin.ignore();

            Goal* goal = user.getGoal(index - 1);

            if (goal != nullptr) {
                goal->setCurrentValue(currentValue);
                cout << "Goal progress updated successfully." << endl;
            }
            else {
                cout << "Invalid goal number." << endl;
            }
        }
        else if (choice == 3) {
            user.displayGoals();
        }

    } while (choice != 0);
}

time_t convertDateToTime(string date) {
    tm timeInfo = {};
    stringstream ss(date);

    ss >> get_time(&timeInfo, "%Y-%m-%d");

    if (ss.fail()) {
        return -1;
    }

    timeInfo.tm_hour = 12;

    return mktime(&timeInfo);
}

void inactivityReminder(User& user) {
    if (user.getWorkoutCount() == 0) {
        cout << "You have no workouts yet. Time to start training!" << endl;
        return;
    }

    time_t latestWorkoutTime = -1;

    for (int i = 0; i < user.getWorkoutCount(); i++) {
        Workout* workout = user.getWorkout(i);

        if (workout != nullptr) {
            time_t workoutTime = convertDateToTime(workout->getDate());

            if (workoutTime > latestWorkoutTime) {
                latestWorkoutTime = workoutTime;
            }
        }
    }

    if (latestWorkoutTime == -1) {
        cout << "Could not check inactivity because workout dates are invalid." << endl;
        return;
    }

    time_t currentTime = time(nullptr);
    double secondsPassed = difftime(currentTime, latestWorkoutTime);
    int daysPassed = secondsPassed / 86400;

    cout << "Days since last workout: " << daysPassed << endl;

    if (daysPassed >= 3) {
        cout << "Reminder: You have not trained for 3 or more days." << endl;
    }
    else {
        cout << "Good job! You have trained recently." << endl;
    }
}

void saveData(User& user) {
    ofstream file("fitness_data.txt");

    if (!file) {
        cout << "Could not open file for saving." << endl;
        return;
    }

    file << user.getName() << endl;
    file << user.getGender() << endl;
    file << user.getAge() << endl;
    file << user.getWeight() << endl;
    file << user.getHeight() << endl;

    file << user.getWorkoutCount() << endl;

    for (int i = 0; i < user.getWorkoutCount(); i++) {
        Workout* workout = user.getWorkout(i);

        file << workout->getDate() << endl;
        file << workout->getDescription() << endl;
        file << workout->getIsCompleted() << endl;

        file << workout->getExerciseCount() << endl;

        for (int j = 0; j < workout->getExerciseCount(); j++) {
            Exercise* exercise = workout->getExercise(j);

            CardioExercise* cardio = dynamic_cast<CardioExercise*>(exercise);

            if (cardio != nullptr) {
                file << "Cardio" << endl;
                file << cardio->getName() << endl;
                file << cardio->getDuration() << endl;
                file << cardio->getDistance() << endl;
            }
            else {
                file << "Strength" << endl;
                file << exercise->getName() << endl;
                file << exercise->getSets() << endl;
                file << exercise->getReps() << endl;
                file << exercise->getWeight() << endl;
            }
        }
    }

    file << user.getGoalCount() << endl;

    for (int i = 0; i < user.getGoalCount(); i++) {
        Goal* goal = user.getGoal(i);

        file << goal->getDescription() << endl;
        file << goal->getTargetValue() << endl;
        file << goal->getCurrentValue() << endl;
    }

    file << user.getPersonalRecordCount() << endl;

    for (int i = 0; i < user.getPersonalRecordCount(); i++) {
        PersonalRecord* record = user.getPersonalRecord(i);

        file << record->getExerciseName() << endl;
        file << record->getValue() << endl;
        file << record->getUnit() << endl;
        file << record->getDateAchieved() << endl;
    }

    file.close();

    cout << "Data saved successfully." << endl;
}


void loadData(User& user) {
    ifstream file("fitness_data.txt");

    if (!file) {
        cout << "No saved data found." << endl;
        return;
    }

    char overwriteChoice;

    cout << "Loading data will overwrite the current user data. Continue? y/n: ";
    cin >> overwriteChoice;
    cin.ignore();

    if (overwriteChoice != 'y' && overwriteChoice != 'Y') {
        cout << "Load cancelled." << endl;
        return;
    }

    user.clearData();

    string name;
    string gender;
    int age;
    double weight;
    double height;

    getline(file, name);
    getline(file, gender);
    file >> age;
    file >> weight;
    file >> height;
    file.ignore();

    user.setName(name);
    user.setGender(gender);
    user.setAge(age);
    user.setWeight(weight);
    user.setHeight(height);

    int workoutCount;
    file >> workoutCount;
    file.ignore();

    for (int i = 0; i < workoutCount; i++) {
        string date;
        string description;
        bool isCompleted;

        getline(file, date);
        getline(file, description);
        file >> isCompleted;
        file.ignore();

        Workout workout(date, description);
        workout.setIsCompleted(isCompleted);

        user.addWorkout(workout);

        Workout* savedWorkout = user.getWorkout(user.getWorkoutCount() - 1);

        int exerciseCount;
        file >> exerciseCount;
        file.ignore();

        for (int j = 0; j < exerciseCount; j++) {
            string exerciseType;
            string exerciseName;

            getline(file, exerciseType);
            getline(file, exerciseName);

            if (exerciseType == "Cardio") {
                int duration;
                double distance;

                file >> duration;
                file >> distance;
                file.ignore();

                Exercise* exercise = new CardioExercise(exerciseName, duration, distance);

                if (savedWorkout != nullptr) {
                    savedWorkout->addExercise(exercise);
                }
            }
            else {
                int sets;
                int reps;
                double exerciseWeight;

                file >> sets;
                file >> reps;
                file >> exerciseWeight;
                file.ignore();

                Exercise* exercise = new StrengthExercise(exerciseName, sets, reps, exerciseWeight);

                if (savedWorkout != nullptr) {
                    savedWorkout->addExercise(exercise);
                }
            }
        }
    }

    int goalCount;
    file >> goalCount;
    file.ignore();

    for (int i = 0; i < goalCount; i++) {
        string description;
        int targetValue;
        int currentValue;

        getline(file, description);
        file >> targetValue;
        file >> currentValue;
        file.ignore();

        Goal goal(description, targetValue);
        goal.setCurrentValue(currentValue);

        user.addGoal(goal);
    }

    int recordCount;
    file >> recordCount;
    file.ignore();

    for (int i = 0; i < recordCount; i++) {
        string exerciseName;
        double value;
        string unit;
        string dateAchieved;

        getline(file, exerciseName);
        file >> value;
        file.ignore();
        getline(file, unit);
        getline(file, dateAchieved);

        PersonalRecord record(exerciseName, value, unit, dateAchieved);
        user.addPersonalRecord(record);
    }

    file.close();

    cout << "Data loaded successfully." << endl;
}

void searchWorkoutByDate(User& user) {
    string date;
    bool found = false;

    cout << endl;
    cout << "Search Workout by Date" << endl;
    cout << "----------------------" << endl;

    cout << "Enter date, for example 2026-05-31: ";
    getline(cin, date);

    for (int i = 0; i < user.getWorkoutCount(); i++) {
        Workout* workout = user.getWorkout(i);

        if (workout != nullptr && workout->getDate() == date) {
            found = true;

            cout << endl;
            cout << "Workout #" << i + 1 << endl;
            workout->displayWorkout();
            workout->displayExercises();
        }
    }

    if (found == false) {
        cout << "No workouts found for this date." << endl;
    }
}