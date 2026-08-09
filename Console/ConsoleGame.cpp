#include "ConsoleGame.h"

#include <iostream>
#include <vector>

#include "ConsoleDice.h"
#include "ConsoleScore.h"
#include "Game.h"

using namespace std;

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