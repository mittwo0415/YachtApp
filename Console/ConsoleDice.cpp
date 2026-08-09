#include "ConsoleDice.h"

#include <iostream>

using namespace std;

// サイコロをコンソールへ表示する
void showDice(
    const vector<int>& dice)
{
    cout << endl;
    cout << "Dice results:" << endl;

    for (int i = 0;
        i < static_cast<int>(dice.size());
        ++i)
    {
        cout << "Dice "
            << i + 1
            << ": "
            << dice[i]
            << endl;
    }
}