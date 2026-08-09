#pragma once

#include <array>
#include <vector>

// 役一覧
enum class ScoreCategory
{
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

// 役の数
constexpr int ScoreCategoryCount = 12;

// 1つの役の記録
struct ScoreEntry
{
    int score = 0;
    bool isUsed = false;
};

// 12役分のスコア表
using ScoreBoard =
std::array<ScoreEntry, ScoreCategoryCount>;

// Aces～Sixesの得点計算
int calculateNumberScore(
    const std::vector<int>& dice,
    int targetNumber
);

// Choiceの得点計算
int calculateChoice(
    const std::vector<int>& dice
);

// Four Diceの得点計算
int calculateFourDice(
    const std::vector<int>& dice
);

// Full Houseの得点計算
int calculateFullHouse(
    const std::vector<int>& dice
);

// Small Straightの得点計算
int calculateSmallStraight(
    const std::vector<int>& dice
);

// Big Straightの得点計算
int calculateBigStraight(
    const std::vector<int>& dice
);

// Yachtの得点計算
int calculateYacht(
    const std::vector<int>& dice
);

// 役名を取得する
const char* getCategoryName(
    ScoreCategory category
);

// 選択した役の得点を計算する
int calculateScoreByCategory(
    const std::vector<int>& dice,
    ScoreCategory category
);

// スコアを登録する
bool recordScore(
    const std::vector<int>& dice,
    ScoreBoard& scoreBoard,
    ScoreCategory category
);

// Aces～Sixesの小計を計算する
int calculateUpperSectionScore(
    const ScoreBoard& scoreBoard
);

// ボーナスを計算する
int calculateUpperBonus(
    const ScoreBoard& scoreBoard
);

// 合計点を計算する
int calculateTotalScore(
    const ScoreBoard& scoreBoard
);