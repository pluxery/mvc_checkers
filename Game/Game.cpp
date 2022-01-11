#include "Game.h"

Position Input(Position &pos) {

    if (KEY[13])_cputs("\nEnter\n");
    std::cout << "Pick your piece (number, letter): " << std::endl;
    std::cin >> pos.oldY;
    std::cin >> pos.oldX;
    std::cout << "Pick your move (number, letter): " << std::endl;
    std::cin >> pos.newY;
    std::cin >> pos.newX;
    return pos;
}


void Launch() {

    //Вывод в консоль _cputs()
    //Считывание клавиши _getch()
    _cputs("Welcome!\n");
    _cputs("Type '1' for start game. \nType any key for exit:\n");
    int input_key;
    input_key = _getch();
    if (input_key == '1') {
        _cputs("Go!\n");
        return;
    }
    _cputs("Bye!\n");
    exit(0);

}

void GetKeyPressed() {
    int i = 0;
    while (i < 256) {
        if (GetAsyncKeyState(i)) KEY[i] = true;
        else KEY[i] = false;
        i++;
    }
}

void Render(BoardModel *boardModel) {
    BoardView::printBoard(boardModel);
    std::string player;
    boardModel->getPlayerTurn() == 1 ? player = "BLACK" : player = "WHITE";
    std::cout << std::endl << "Turn: " + player << std::endl;
}

void Update(Position pos, BoardModel *boardModel) {
    BoardController::tryMove(pos.oldY, pos.oldX, pos.newY, pos.newX, boardModel);
}
