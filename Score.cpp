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

// Four Diceの得点計算
int calculateFourDice(const vector<int>& dice) {
    // 出目1～6が、それぞれ何個あるかを数える
    int counts[7] = {};

    for (int value : dice) {
        counts[value]++;
    }

    // 同じ目が4個以上あるか確認する
    for (int number = 1; number <= 6; number++) {
        if (counts[number] >= 4) {
            return calculateChoice(dice);
        }
    }

    return 0;
}