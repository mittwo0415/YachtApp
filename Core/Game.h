#pragma once

#include <vector>

// 1ターンで使用するサイコロの数
constexpr int DiceCount = 5;

// 1ターンで可能な振り直し回数
constexpr int MaxRerollCount = 2;

// ターン開始時のサイコロを生成する
std::vector<int> startTurn();

// 指定したサイコロを振り直す
void rerollSelectedDice(
    std::vector<int>& dice,
    const std::vector<int>& indexes
);