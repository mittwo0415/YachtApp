#include "ConsoleGame.h"

#include <iostream>
#include <vector>

#include "ConsoleDice.h"
#include "ConsoleScore.h"
#include "Game.h"

using namespace std;

// コンソール版ゲーム全体を実行する
void runGameConsole()
{
    GameState gameState;

    while (!isGameFinished(gameState))
    {
        const Player currentPlayer =
            getCurrentPlayer(gameState);

        // Player Aの開始時のみラウンドを表示
        if (currentPlayer == Player::PlayerA)
        {
            cout << endl;
            cout << "========================" << endl;
            cout << "Round "
                << gameState.currentRound
                << " / "
                << ScoreCategoryCount
                << endl;
            cout << "========================" << endl;
        }

        cout << endl;

        if (currentPlayer == Player::PlayerA)
        {
            cout << "Player A Turn" << endl;
        }
        else
        {
            cout << "Player B Turn" << endl;
        }

        // Core側から現在のプレイヤーのスコアボードを取得
        ScoreBoard& scoreBoard =
            getCurrentScoreBoard(gameState);

        playTurnConsole(scoreBoard);

        // Core側で次のプレイヤー / 次のラウンドへ進める
        advanceTurn(gameState);
    }

    // 最終結果
    cout << endl;
    cout << "========================" << endl;
    cout << "Final Results" << endl;
    cout << "========================" << endl;

    cout << endl;
    cout << "Player A" << endl;
    showScoreBoard(
        gameState.playerA
    );

    cout << endl;
    cout << "Player B" << endl;
    showScoreBoard(
        gameState.playerB
    );

    const int playerATotal =
        getPlayerATotalScore(gameState);

    const int playerBTotal =
        getPlayerBTotalScore(gameState);

    cout << endl;
    cout << "Player A Total: "
        << playerATotal
        << endl;

    cout << "Player B Total: "
        << playerBTotal
        << endl;

    cout << endl;

    const GameResult result =
        getGameResult(gameState);

    if (result == GameResult::PlayerAWin)
    {
        cout << "Player A Wins!" << endl;
    }
    else if (result == GameResult::PlayerBWin)
    {
        cout << "Player B Wins!" << endl;
    }
    else
    {
        cout << "Draw!" << endl;
    }

    cout << endl;
    cout << "Press Enter to exit...";

    cin.ignore();
    cin.get();
}

// コンソール上でプレイヤー1人分の1ターンを実行する
void playTurnConsole(ScoreBoard& scoreBoard)
{
    // 最初に5個すべて振る
    vector<int> dice = startTurn();

    showDice(dice);

    // 最大2回まで振り直す
    for (int rerollCount = 1;
        rerollCount <= MaxRerollCount;
        ++rerollCount)
    {
        char choice;

        cout << endl;
        cout << "[r] Reroll" << endl;
        cout << "[q] Finish rolling" << endl;
        cout << "Select: ";

        cin >> choice;

        // 振り直さず終了
        if (choice == 'q')
        {
            break;
        }

        // 振り直す
        if (choice == 'r')
        {
            cout << endl;
            cout << "Enter dice numbers to reroll." << endl;
            cout << "Example: 1 3 5" << endl;
            cout << "Enter 0 when finished: ";

            vector<int> indexes;
            int diceNumber;

            while (cin >> diceNumber &&
                diceNumber != 0)
            {
                if (diceNumber >= 1 &&
                    diceNumber <= DiceCount)
                {
                    indexes.push_back(
                        diceNumber - 1
                    );
                }
                else
                {
                    cout << "Invalid number." << endl;
                }
            }

            // 選択されたサイコロをCore側で振り直す
            rerollSelectedDice(
                dice,
                indexes
            );

            cout << endl;
            cout << "Reroll "
                << rerollCount
                << " / "
                << MaxRerollCount
                << " completed."
                << endl;

            showDice(dice);
        }
        else
        {
            cout << "Invalid command." << endl;

            // 無効入力では回数を消費しない
            --rerollCount;
        }
    }

    // 最終結果
    cout << endl;
    cout << "Final result:" << endl;

    showDice(dice);

    // 役を選択してスコア表へ登録
    selectAndRecordScoreConsole(
        dice,
        scoreBoard
    );

    // 現在のスコア表
    cout << endl;
    cout << "Current Score:" << endl;

    showScoreBoard(scoreBoard);
}