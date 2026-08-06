#include <iostream>
#include <limits>
#include <vector>

#include "Dice.h"
#include "Score.h"

using namespace std;

int main() {
    vector<int> dice(5);
    ScoreBoard scoreBoard;

    // 全12ターン行う
    for (int turn = 1; turn <= ScoreCategoryCount; turn++) {

        cout << endl;
        cout << "========================" << endl;
        cout << "Turn " << turn
            << " / " << ScoreCategoryCount << endl;
        cout << "========================" << endl;

        // 毎ターン最初に5個すべて振る
        rollAllDice(dice);
        showDice(dice);

        // 最大2回まで振り直す
        for (int rerollCount = 1; rerollCount <= 2; rerollCount++) {
            char choice;

            cout << endl;
            cout << "[r] Reroll" << endl;
            cout << "[q] Finish rolling" << endl;
            cout << "Select: ";

            cin >> choice;

            // 振り直しを終了する
            if (choice == 'q') {
                break;
            }

            // サイコロを振り直す
            if (choice == 'r') {
                cout << endl;
                cout << "Enter dice numbers to reroll." << endl;
                cout << "Example: 1 3 5" << endl;
                cout << "Enter 0 when finished: ";

                int diceNumber;

                while (cin >> diceNumber && diceNumber != 0) {
                    if (diceNumber >= 1 && diceNumber <= 5) {
                        rerollDice(dice, diceNumber - 1);
                    }
                    else {
                        cout << "Invalid number." << endl;
                    }
                }

                cout << endl;
                cout << "Reroll "
                    << rerollCount
                    << " / 2 completed." << endl;

                showDice(dice);
            }
            else {
                cout << "Invalid command." << endl;

                // 無効入力では振り直し回数を消費しない
                rerollCount--;
            }
        }

        cout << endl;
        cout << "Final result:" << endl;
        showDice(dice);

        // プレイヤーが役を選び、得点を登録する
        selectAndRecordScore(dice, scoreBoard);

        cout << endl;
        cout << "Score after turn "
            << turn << ":" << endl;

        showScoreBoard(scoreBoard);
    }

    // 全12ターン終了
    cout << endl;
    cout << "========================" << endl;
    cout << "Game Over" << endl;
    cout << "========================" << endl;

    showScoreBoard(scoreBoard);

    cout << endl;
    cout << "Final total score: "
        << calculateTotalScore(scoreBoard)
        << endl;

    // コンソールをすぐ閉じないようにする
    cout << endl;
    cout << "Press Enter to exit...";

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );
    cin.get();

    return 0;
}