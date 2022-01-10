#pragma once

#include "../Model/BoradModel.h"
#include <string>
#include "../View/BoardView.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Position {
    int oldY, newY;
    char oldX, newX;
};

void Render(BoardModel *boardModel) {
    BoardView::printBoard(boardModel);
    string Player;
    boardModel->getPlayerTurn() == 1 ? Player = "BLACK" : Player = "WHITE";
    cout << endl << "Turn: " + Player << endl;
}

Position Input(Position &pos) {
    cout << "Pick your piece (number, letter): " << endl;
    cin >> pos.oldY;
    cin >> pos.oldX;
    cout << "Pick your move (number, letter): " << endl;
    cin >> pos.newY;
    cin >> pos.newX;

    return pos;
}

void Update(Position pos, BoardModel *boardModel) {
    BoardController::tryMove(pos.oldY, pos.oldX, pos.newY, pos.newX, boardModel);
}




