#include <iostream>

using namespace std;

// Tank level zones
enum TankLevel {
    EMPTY = 0,
    LOW = 1,
    MID = 2,
    ALMOST_FULL = 3,
    FULL = 4
};

int main() {
    int levelInput;
    bool motorOn = false;    // false = OFF, true = ON
    bool warningOn = false;  // warning (almost full)

    cout << "Water Tank Controller Simulation\n";
    cout << "Levels: 0=EMPTY, 1=LOW, 2=MID, 3=ALMOST_FULL, 4=FULL\n";
    cout << "Enter -1 to exit.\n\n";

    while (true) {
        cout << "Enter level: ";
        cin >> levelInput;

        if (!cin) {
            cout << "Input error. Exiting.\n";
            break;
        }

        if (levelInput == -1) {
            cout << "Exiting.\n";
            break;
        }

        if (levelInput < 0 || levelInput > 4) {
            cout << "Invalid level. Try again.\n";
            continue;
        }

        TankLevel level = static_cast<TankLevel>(levelInput);

        // --------- Motor logic (from our table) ---------
        // If tank is EMPTY or LOW -> motor must be ON
        if (level == EMPTY || level == LOW) {
            motorOn = true;
        }
        // If tank is FULL -> motor must be OFF
        else if (level == FULL) {
            motorOn = false;
        }
        // If MID or ALMOST_FULL -> keep previous motorOn value (no change)

        // --------- Warning logic ----------
        // Warning only when tank is ALMOST_FULL and motor is still ON
        if (level == ALMOST_FULL && motorOn) {
            warningOn = true;
        } else {
            warningOn = false;
        }

        // --------- Print status ----------
        cout << "Motor   : " << (motorOn ? "ON" : "OFF") << "\n";
        cout << "Warning : " << (warningOn ? "ON" : "OFF") << "\n\n";
    }

    return 0;
}
