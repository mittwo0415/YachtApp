#include <iostream>
#include <vector>
#include <limits>

#include "Dice.h"
#include "Score.h"

using namespace std;

int main() {

    vector<int> dice(5);

    // 最初に5個振る
    rollAllDice(dice);

    showDice(dice);

    // 最大2回まで振り直し
    for (int rerollCount = 1; rerollCount <= 2; rerollCount++) {

        char choice;

        cout << endl;
        cout << "[r] Reroll" << endl;
        cout << "[q] Finish" << endl;
        cout << "Select: ";

        cin >> choice;

        if (choice == 'q') {
            break;
        }

        if (choice == 'r') {

            cout << endl;
            cout << "Enter dice numbers to reroll." << endl;
            cout << "Example: 1 3 5" << endl;
            cout << "Enter 0 when finished." << endl;

            int diceNumber;

            while (cin >> diceNumber && diceNumber != 0) {

                if (diceNumber >= 1 && diceNumber <= 5) {
                    rerollDice(dice, diceNumber - 1);
                }
                else {
                    cout << "Invalid number." << endl;
                }
            }

            showDice(dice);
        }
        else {
            cout << "Invalid command." << endl;
            rerollCount--;
        }
    }

    cout << endl;
    cout << "Final result:" << endl;
    showDice(dice);

    cout << endl;
    cout << "Choice : " << calculateChoice(dice) << endl;

    cout << endl;
    cout << "Press Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}