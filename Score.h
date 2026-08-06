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

// Full Houseの得点計算
int calculateFullHouse(const std::vector<int>& dice);

// Small Straightの得点計算
int calculateSmallStraight(const std::vector<int>& dice);

// Big Straightの得点計算
int calculateBigStraight(const std::vector<int>& dice);