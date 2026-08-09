#include "Game.h"

#include "Dice.h"

using namespace std;

// ターン開始時に5個のサイコロを振る
vector<int> startTurn()
{
    vector<int> dice(DiceCount);

    rollAllDice(dice);

    return dice;
}

// 選択されたサイコロを振り直す
void rerollSelectedDice(
    vector<int>& dice,
    const vector<int>& indexes)
{
    for (int index : indexes)
    {
        if (index >= 0 &&
            index < static_cast<int>(dice.size()))
        {
            rerollDice(dice, index);
        }
    }
}

// 現在のプレイヤーを取得する
Player getCurrentPlayer(
    const GameState& gameState)
{
    return gameState.currentPlayer;
}

// 現在のプレイヤーのスコアボードを取得する
ScoreBoard& getCurrentScoreBoard(
    GameState& gameState)
{
    if (gameState.currentPlayer == Player::PlayerA)
    {
        return gameState.playerA;
    }

    return gameState.playerB;
}

// 現在のターンを終了し、次のプレイヤーへ進める
void advanceTurn(
    GameState& gameState)
{
    // Player Aの次はPlayer B
    if (gameState.currentPlayer == Player::PlayerA)
    {
        gameState.currentPlayer = Player::PlayerB;
        return;
    }

    // Player Bの次は次ラウンドのPlayer A
    gameState.currentPlayer = Player::PlayerA;
    ++gameState.currentRound;
}

// ゲームが終了しているか判定する
bool isGameFinished(
    const GameState& gameState)
{
    return gameState.currentRound >
        ScoreCategoryCount;
}

// Player Aの合計得点を取得する
int getPlayerATotalScore(
    const GameState& gameState)
{
    return calculateTotalScore(
        gameState.playerA
    );
}

// Player Bの合計得点を取得する
int getPlayerBTotalScore(
    const GameState& gameState)
{
    return calculateTotalScore(
        gameState.playerB
    );
}

// ゲームの勝敗を判定する
GameResult getGameResult(
    const GameState& gameState)
{
    const int playerATotal =
        getPlayerATotalScore(gameState);

    const int playerBTotal =
        getPlayerBTotalScore(gameState);

    if (playerATotal > playerBTotal)
    {
        return GameResult::PlayerAWin;
    }

    if (playerBTotal > playerATotal)
    {
        return GameResult::PlayerBWin;
    }

    return GameResult::Draw;
}