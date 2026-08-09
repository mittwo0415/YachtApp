#include "Game.h"

#include "Dice.h"

using namespace std;

// ターン開始時に5個のサイコロを振る
vector<int> startTurn()
{
    vector<int> dice(DiceCount);

    rollAllDice(dice);

    return dice;
}

// 選択されたサイコロを振り直す
void rerollSelectedDice(
    vector<int>& dice,
    const vector<int>& indexes)
{
    for (int index : indexes)
    {
        if (index >= 0 &&
            index < static_cast<int>(dice.size()))
        {
            rerollDice(dice, index);
        }
    }
}