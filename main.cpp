#include <iostream>
#include<vector>
#include "Model/BoradModel.h"
#include "View/BoardView.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    auto *boardModel = new BoardModel();

    while (!boardModel->checkWinCondition()) {
        cout << "Score for white: " << 12 - boardModel->getBlackCounter() << endl;
        cout << "Score for black: " << 12 - boardModel->getWhiteCounter() << endl << endl;

        BoardView::printBoard(boardModel);
        int oldY, newY;
        char oldX, newX;

        cout << endl;
        if (boardModel->getPlayerTurn() == -1) { cout << endl << "Turn: WHITE" << endl; }
        else { cout << endl << "Turn: BLACK" << endl; }

        cout << "Pick your piece (number, letter): " << endl;
        cin >> oldY;
        cin >> oldX;

        cout << "Pick your move (number, letter): " << endl;
        cin >> newY;
        cin >> newX;

        BoardController::tryMove(oldY, oldX, newY, newX, boardModel);
    }
    return 0;
}
