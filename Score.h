#pragma once

#include <vector>

// 役一覧
enum class ScoreCategory {

    Aces,
    Deuces,
    Threes,
    Fours,
    Fives,
    Sixes,

    Choice,

    FourDice,
    FullHouse,
    SmallStraight,
    BigStraight,
    Yacht
};

// Choiceの得点計算
int calculateChoice(const std::vector<int>& dice);