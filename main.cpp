#include <iostream>
#include "User.h"
#include "Functions.h"

using namespace std;
int main() {
    User user;
    int choice;
    do {
        cout << endl;
        cout << "Fitness Tracker" << endl;
        cout << "---------------" << endl;
        cout << "1. Manage user profile" << endl;
        cout << "2. Manage workouts" << endl;
        cout << "3. Workout history" << endl;
        cout << "4. Display profile" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            manageUserProfile(user);
        }
        else if (choice == 2) {
            manageWorkouts(user);
        }
        else if (choice == 3) {
            workoutHistory(user);
        }
        else if (choice == 4) {
            user.displayProfile();
        }
    } while (choice != 0);
    cout << "Goodbye!" << endl;
    return 0;
}