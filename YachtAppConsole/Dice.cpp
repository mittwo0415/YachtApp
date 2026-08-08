#include "Dice.h"

#include <iostream>
#include <random>

using namespace std;

// サイコロを1個振る
int rollDice() {

    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(1, 6);

    return dist(gen);
}

// サイコロを5個振る
void rollAllDice(vector<int>& dice) {

    for (int i = 0; i < dice.size(); i++) {
        dice[i] = rollDice();
    }
}

// 指定したサイコロを振り直す
void rerollDice(vector<int>& dice, int index) {

    dice[index] = rollDice();
}

// サイコロを表示する
void showDice(const vector<int>& dice) {

    cout << endl;
    cout << "Dice results:" << endl;

    for (int i = 0; i < dice.size(); i++) {
        cout << "Dice " << i + 1 << ": " << dice[i] << endl;
    }
}