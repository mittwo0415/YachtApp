#include <iostream>

#include "ConsoleGame.h"
#include "ConsoleScore.h"
#include "Score.h"

using namespace std;

int main()
{
    ScoreBoard playerA;
    ScoreBoard playerB;

    // 全12ラウンド
    for (int round = 1;
        round <= ScoreCategoryCount;
        ++round)
    {
        cout << endl;
        cout << "========================" << endl;
        cout << "Round "
            << round
            << " / "
            << ScoreCategoryCount
            << endl;
        cout << "========================" << endl;

        // Player A
        cout << endl;
        cout << "Player A Turn" << endl;

        playTurnConsole(playerA);

        // Player B
        cout << endl;
        cout << "Player B Turn" << endl;

        playTurnConsole(playerB);
    }

    // 最終結果
    cout << endl;
    cout << "========================" << endl;
    cout << "Final Results" << endl;
    cout << "========================" << endl;

    cout << endl;
    cout << "Player A" << endl;
    showScoreBoard(playerA);

    cout << endl;
    cout << "Player B" << endl;
    showScoreBoard(playerB);

    const int playerATotal =
        calculateTotalScore(playerA);

    const int playerBTotal =
        calculateTotalScore(playerB);

    cout << endl;
    cout << "Player A Total: "
        << playerATotal
        << endl;

    cout << "Player B Total: "
        << playerBTotal
        << endl;

    cout << endl;

    // 勝敗判定
    if (playerATotal > playerBTotal)
    {
        cout << "Player A Wins!" << endl;
    }
    else if (playerBTotal > playerATotal)
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

    return 0;
}