#pragma once

#include <vector>

#include "Score.h"

// スコア表をコンソールへ表示する
void showScoreBoard(
    const ScoreBoard& scoreBoard
);

// プレイヤーに役を選択させてスコア表へ登録する
void selectAndRecordScoreConsole(
    const std::vector<int>& dice,
    ScoreBoard& scoreBoard
);