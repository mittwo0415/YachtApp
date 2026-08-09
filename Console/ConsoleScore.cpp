#include "ConsoleScore.h"

#include <iostream>
#include <limits>

using namespace std;

// スコア表を表示する
void showScoreBoard(
    const ScoreBoard& scoreBoard)
{
    cout << endl;
    cout << "Score Board" << endl;
    cout << "------------------------" << endl;

    for (int i = 0;
        i < ScoreCategoryCount;
        ++i)
    {
        const ScoreCategory category =
            static_cast<ScoreCategory>(i);

        cout << i + 1
            << ". "
            << getCategoryName(category)
            << " : ";

        if (scoreBoard[i].isUsed)
        {
            cout << scoreBoard[i].score;
        }
        else
        {
            cout << "-";
        }

        cout << endl;
    }

    cout << "------------------------" << endl;

    cout << "Upper subtotal: "
        << calculateUpperSectionScore(scoreBoard)
        << endl;

    cout << "Upper bonus   : "
        << calculateUpperBonus(scoreBoard)
        << endl;

    cout << "------------------------" << endl;

    cout << "Total: "
        << calculateTotalScore(scoreBoard)
        << endl;
}

// プレイヤーに役を選択させてスコア表へ登録する
void selectAndRecordScoreConsole(
    const vector<int>& dice,
    ScoreBoard& scoreBoard)
{
    while (true)
    {
        showScoreBoard(scoreBoard);

        cout << endl;
        cout << "Select a category number: ";

        int categoryNumber;
        cin >> categoryNumber;

        // 整数以外が入力された場合
        if (!cin)
        {
            cout << "Invalid input." << endl;

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }

        // 1～12以外
        if (categoryNumber < 1 ||
            categoryNumber > ScoreCategoryCount)
        {
            cout << "Invalid category number."
                << endl;

            continue;
        }

        const int index =
            categoryNumber - 1;

        const ScoreCategory category =
            static_cast<ScoreCategory>(index);

        // Core側でスコアを登録
        if (!recordScore(
            dice,
            scoreBoard,
            category))
        {
            cout
                << "This category has already been used."
                << endl;

            continue;
        }

        cout << endl;
        cout << getCategoryName(category)
            << " score: "
            << scoreBoard[index].score
            << endl;

        break;
    }
}