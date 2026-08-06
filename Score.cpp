#include <iostream>

#include "Score.h"

using namespace std;

// 指定した数字の出目だけを合計する
int calculateNumberScore(const vector<int>& dice, int targetNumber) {

    int total = 0;

    for (int value : dice) {
        if (value == targetNumber) {
            total += value;
        }
    }

    return total;
}

// Choiceの得点計算
int calculateChoice(const vector<int>& dice) {

    int total = 0;

    for (int value : dice) {
        total += value;
    }

    return total;
}

// Four Diceの得点計算
int calculateFourDice(const vector<int>& dice) {
    // 出目1～6が、それぞれ何個あるかを数える
    int counts[7] = {};

    for (int value : dice) {
        counts[value]++;
    }

    // 同じ目が4個以上あるか確認する
    for (int number = 1; number <= 6; number++) {
        if (counts[number] >= 4) {
            return calculateChoice(dice);
        }
    }

    return 0;
}

// Full Houseの得点計算
int calculateFullHouse(const vector<int>& dice) {
    // 出目1～6が、それぞれ何個あるかを数える
    int counts[7] = {};

    for (int value : dice) {
        counts[value]++;
    }

    bool hasThree = false;
    bool hasTwo = false;

    // 3個同じ目と2個同じ目があるか確認する
    for (int number = 1; number <= 6; number++) {
        if (counts[number] == 3) {
            hasThree = true;
        }
        else if (counts[number] == 2) {
            hasTwo = true;
        }
    }

    if (hasThree && hasTwo) {
        return calculateChoice(dice);
    }

    return 0;
}

// Small Straightの得点計算
int calculateSmallStraight(const vector<int>& dice) {
    // 出目1～6が存在するか記録する
    bool exists[7] = {};

    for (int value : dice) {
        exists[value] = true;
    }

    // 1-2-3-4
    bool firstStraight =
        exists[1] &&
        exists[2] &&
        exists[3] &&
        exists[4];

    // 2-3-4-5
    bool secondStraight =
        exists[2] &&
        exists[3] &&
        exists[4] &&
        exists[5];

    // 3-4-5-6
    bool thirdStraight =
        exists[3] &&
        exists[4] &&
        exists[5] &&
        exists[6];

    if (firstStraight || secondStraight || thirdStraight) {
        return 15;
    }

    return 0;
}

// Big Straightの得点計算
int calculateBigStraight(const vector<int>& dice) {
    // 出目1～6が存在するか記録する
    bool exists[7] = {};

    for (int value : dice) {
        exists[value] = true;
    }

    // 1-2-3-4-5
    bool firstStraight =
        exists[1] &&
        exists[2] &&
        exists[3] &&
        exists[4] &&
        exists[5];

    // 2-3-4-5-6
    bool secondStraight =
        exists[2] &&
        exists[3] &&
        exists[4] &&
        exists[5] &&
        exists[6];

    if (firstStraight || secondStraight) {
        return 30;
    }

    return 0;
}

// Yachtの得点計算
int calculateYacht(const vector<int>& dice) {

    // 出目1～6が、それぞれ何個あるかを数える
    int counts[7] = {};

    for (int value : dice) {
        counts[value]++;
    }

    // 同じ目が5個あるか確認する
    for (int number = 1; number <= 6; number++) {
        if (counts[number] == 5) {
            return 50;
        }
    }

    return 0;
}

// 役名を取得する
const char* getCategoryName(ScoreCategory category) {
    switch (category) {
    case ScoreCategory::Aces:
        return "Aces";

    case ScoreCategory::Deuces:
        return "Deuces";

    case ScoreCategory::Threes:
        return "Threes";

    case ScoreCategory::Fours:
        return "Fours";

    case ScoreCategory::Fives:
        return "Fives";

    case ScoreCategory::Sixes:
        return "Sixes";

    case ScoreCategory::Choice:
        return "Choice";

    case ScoreCategory::FourDice:
        return "Four Dice";

    case ScoreCategory::FullHouse:
        return "Full House";

    case ScoreCategory::SmallStraight:
        return "Small Straight";

    case ScoreCategory::BigStraight:
        return "Big Straight";

    case ScoreCategory::Yacht:
        return "Yacht";
    }

    return "Unknown";
}

// スコア表を表示する
void showScoreBoard(const ScoreBoard& scoreBoard) {
    cout << endl;
    cout << "Score Board" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < ScoreCategoryCount; i++) {
        ScoreCategory category =
            static_cast<ScoreCategory>(i);

        cout << i + 1 << ". "
            << getCategoryName(category)
            << " : ";

        if (scoreBoard[i].isUsed) {
            cout << scoreBoard[i].score;
        }
        else {
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

// 合計点を計算する
int calculateTotalScore(const ScoreBoard& scoreBoard) {
    int total = 0;

    for (const ScoreEntry& entry : scoreBoard) {
        if (entry.isUsed) {
            total += entry.score;
        }
    }

    // Aces～Sixesのボーナスを加算する
    total += calculateUpperBonus(scoreBoard);

    return total;
}

// 選択した役の得点を計算する
int calculateScoreByCategory(
    const vector<int>& dice,
    ScoreCategory category
) {
    switch (category) {
    case ScoreCategory::Aces:
        return calculateNumberScore(dice, 1);

    case ScoreCategory::Deuces:
        return calculateNumberScore(dice, 2);

    case ScoreCategory::Threes:
        return calculateNumberScore(dice, 3);

    case ScoreCategory::Fours:
        return calculateNumberScore(dice, 4);

    case ScoreCategory::Fives:
        return calculateNumberScore(dice, 5);

    case ScoreCategory::Sixes:
        return calculateNumberScore(dice, 6);

    case ScoreCategory::Choice:
        return calculateChoice(dice);

    case ScoreCategory::FourDice:
        return calculateFourDice(dice);

    case ScoreCategory::FullHouse:
        return calculateFullHouse(dice);

    case ScoreCategory::SmallStraight:
        return calculateSmallStraight(dice);

    case ScoreCategory::BigStraight:
        return calculateBigStraight(dice);

    case ScoreCategory::Yacht:
        return calculateYacht(dice);
    }

    return 0;
}

// プレイヤーに役を選ばせてスコア表へ登録する
void selectAndRecordScore(
    const vector<int>& dice,
    ScoreBoard& scoreBoard
) {
    while (true) {
        showScoreBoard(scoreBoard);

        cout << endl;
        cout << "Select a category number: ";

        int categoryNumber;
        cin >> categoryNumber;

        // 1～12以外は無効
        if (categoryNumber < 1 ||
            categoryNumber > ScoreCategoryCount) {
            cout << "Invalid category number." << endl;
            continue;
        }

        int index = categoryNumber - 1;

        // 使用済みの役は選択できない
        if (scoreBoard[index].isUsed) {
            cout << "This category has already been used." << endl;
            continue;
        }

        ScoreCategory category =
            static_cast<ScoreCategory>(index);

        int score =
            calculateScoreByCategory(dice, category);

        scoreBoard[index].score = score;
        scoreBoard[index].isUsed = true;

        cout << endl;
        cout << getCategoryName(category)
            << " score: "
            << score
            << endl;

        break;
    }
}

// Aces～Sixesの小計を計算する
int calculateUpperSectionScore(const ScoreBoard& scoreBoard) {
    int total = 0;

    // Aces～Sixesはインデックス0～5
    for (int i = 0; i < 6; i++) {
        if (scoreBoard[i].isUsed) {
            total += scoreBoard[i].score;
        }
    }

    return total;
}

// Aces～Sixesの合計が63点以上なら35点
int calculateUpperBonus(const ScoreBoard& scoreBoard) {
    if (calculateUpperSectionScore(scoreBoard) >= 63) {
        return 35;
    }

    return 0;
}