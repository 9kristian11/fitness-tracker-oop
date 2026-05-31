#include <iostream>
#include "User.h"
#include "Functions.h"

using namespace std;

int main() {
 User user;
int choice;
char loadChoice;
bool dataLoaded = false;


cout << "Do you want to load saved data? y/n: ";
cin >> loadChoice;
cin.ignore();

if (loadChoice == 'y' || loadChoice == 'Y') {
    loadData(user);
    dataLoaded = true;

}
    

    do {
        cout << endl;
        cout << "Fitness Tracker" << endl;
        cout << "---------------" << endl;
        cout << "1. Manage user profile" << endl;
        cout << "2. Manage workouts" << endl;
        cout << "3. Workout history" << endl;
        cout << "4. Track personal records" << endl;
        cout << "5. Monthly statistics" << endl;
        cout << "6. Manage goals" << endl;
        cout << "7. Inactivity reminder" << endl;
        cout << "8. Display profile" << endl;
        cout << "9. Save data" << endl;
        cout << "10. Load data" << endl;
        cout << "11. Search Workout by Date" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            manageUserProfile(user, dataLoaded);
        }
        else if (choice == 2) {
            manageWorkouts(user);
        }
        else if (choice == 3) {
            workoutHistory(user);
        }
        else if (choice == 4) {
            trackPR(user);
        }
        else if (choice == 5) {
            monthlyStats(user);
        }
        else if (choice == 6) {
            manageGoals(user);
        }
        else if (choice == 7) {
            inactivityReminder(user);
        }
        else if (choice == 8) {
            user.displayProfile();
        }
        else if (choice == 9) {
            saveData(user);
        }
        else if (choice == 10) {
            loadData(user);
        }
        else if (choice == 11) {
    searchWorkoutByDate(user);
}
    } while (choice != 0);

    cout << "Goodbye!" << endl;

    return 0;
}