#pragma once

#include <vector>

// サイコロを1個振る
int rollDice();

// サイコロをすべて振る
void rollAllDice(
    std::vector<int>& dice
);

// 指定したサイコロを振り直す
void rerollDice(
    std::vector<int>& dice,
    int index
);