#include "Dice.h"

#include <random>

using namespace std;

// サイコロを1個振る
int rollDice()
{
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(1, 6);

    return dist(gen);
}

// サイコロをすべて振る
void rollAllDice(
    vector<int>& dice)
{
    for (int i = 0;
        i < static_cast<int>(dice.size());
        ++i)
    {
        dice[i] = rollDice();
    }
}

// 指定したサイコロを振り直す
void rerollDice(
    vector<int>& dice,
    int index)
{
    dice[index] = rollDice();
}