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

// Full Houseの得点計算
int calculateFullHouse(const vector<int>& dice) {
    // 出目1～6が、それぞれ何個あるかを数える
    int counts[7] = {};

    for (int value : dice) {
        counts[value]++;
    }

    bool hasThree = false;
    bool hasTwo = false;

    // 3個同じ目と2個同じ目があるか確認する
    for (int number = 1; number <= 6; number++) {
        if (counts[number] == 3) {
            hasThree = true;
        }
        else if (counts[number] == 2) {
            hasTwo = true;
        }
    }

    if (hasThree && hasTwo) {
        return calculateChoice(dice);
    }

    return 0;
}

// Small Straightの得点計算
int calculateSmallStraight(const vector<int>& dice) {
    // 出目1～6が存在するか記録する
    bool exists[7] = {};

    for (int value : dice) {
        exists[value] = true;
    }

    // 1-2-3-4
    bool firstStraight =
        exists[1] &&
        exists[2] &&
        exists[3] &&
        exists[4];

    // 2-3-4-5
    bool secondStraight =
        exists[2] &&
        exists[3] &&
        exists[4] &&
        exists[5];

    // 3-4-5-6
    bool thirdStraight =
        exists[3] &&
        exists[4] &&
        exists[5] &&
        exists[6];

    if (firstStraight || secondStraight || thirdStraight) {
        return 15;
    }

    return 0;
}

// Big Straightの得点計算
int calculateBigStraight(const vector<int>& dice) {
    // 出目1～6が存在するか記録する
    bool exists[7] = {};

    for (int value : dice) {
        exists[value] = true;
    }

    // 1-2-3-4-5
    bool firstStraight =
        exists[1] &&
        exists[2] &&
        exists[3] &&
        exists[4] &&
        exists[5];

    // 2-3-4-5-6
    bool secondStraight =
        exists[2] &&
        exists[3] &&
        exists[4] &&
        exists[5] &&
        exists[6];

    if (firstStraight || secondStraight) {
        return 30;
    }

    return 0;
}