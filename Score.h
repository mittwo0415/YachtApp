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

// Aces〜Sixesの得点計算
int calculateNumberScore(const std::vector<int>& dice, int targetNumber);

// Choiceの得点計算
int calculateChoice(const std::vector<int>& dice);

// Four Diceの得点計算
int calculateFourDice(const std::vector<int>& dice);