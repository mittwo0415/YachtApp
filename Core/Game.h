#pragma once

#include <vector>

#include "Score.h"

// 1ターンで使用するサイコロの数
constexpr int DiceCount = 5;

// 1ターンで可能な振り直し回数
constexpr int MaxRerollCount = 2;

// プレイヤー
enum class Player
{
    PlayerA,
    PlayerB
};

// ゲームの勝敗結果
enum class GameResult
{
    PlayerAWin,
    PlayerBWin,
    Draw
};

// ゲーム全体の状態
struct GameState
{
    ScoreBoard playerA;
    ScoreBoard playerB;

    int currentRound = 1;
    Player currentPlayer = Player::PlayerA;
};

// ターン開始時のサイコロを生成する
std::vector<int> startTurn();

// 指定したサイコロを振り直す
void rerollSelectedDice(
    std::vector<int>& dice,
    const std::vector<int>& indexes
);

// 現在のプレイヤーを取得する
Player getCurrentPlayer(
    const GameState& gameState
);

// 現在のプレイヤーのスコアボードを取得する
ScoreBoard& getCurrentScoreBoard(
    GameState& gameState
);

// 現在のターンを終了し、次のプレイヤーへ進める
void advanceTurn(
    GameState& gameState
);

// ゲームが終了しているか判定する
bool isGameFinished(
    const GameState& gameState
);

// Player Aの合計得点を取得する
int getPlayerATotalScore(
    const GameState& gameState
);

// Player Bの合計得点を取得する
int getPlayerBTotalScore(
    const GameState& gameState
);

// ゲームの勝敗を判定する
GameResult getGameResult(
    const GameState& gameState
);