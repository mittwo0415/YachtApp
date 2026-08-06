#include "Score.h"

using namespace std;

// Choiceの得点計算
int calculateChoice(const vector<int>& dice) {

    int total = 0;

    for (int value : dice) {
        total += value;
    }

    return total;
}