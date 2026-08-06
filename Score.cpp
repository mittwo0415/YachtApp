#include "Score.h"

using namespace std;

// 指定した数字の出目だけを合計する
int calculateNumberScore(const vector<int>& dice, int targetNumber) {

    int total = 0;

    for (int value : dice) {
        if (value == targetNumber) {
            total += value;
        }
    }

    return total;
}

// Choiceの得点計算
int calculateChoice(const vector<int>& dice) {

    int total = 0;

    for (int value : dice) {
        total += value;
    }

    return total;
}