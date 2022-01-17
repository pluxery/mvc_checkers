#include "Game.h"

using milliseconds = std::chrono::milliseconds;

void Buffer::parseCoords() {
    this->oldY--;
    this->newY--;

    int nums[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int code = 65, letter = 0; code < 73; code++, letter++) {
        if (this->oldX == code) {
            this->oldX = nums[letter];
        }
        if (this->newX == code) {
            this->newX = nums[letter];
        }
    }
}

void GetKeyPressed() {
    int i = 0;
    while (i < 256) {
        if (GetAsyncKeyState(i)) KEY[i] = true;
        else KEY[i] = false;
        i++;
    }
}

void AsyncExitListener() {
    while (true) {
        GetKeyPressed();
        if (KEY[VK_ESCAPE]) {
            std::cout << "Bye!" << std::endl;
            exit(0);
        }
        std::this_thread::sleep_for(milliseconds(500));
    }
}

Buffer Input(Buffer &coords) {
    std::cout << "Pick your piece (number, letter):" << std::endl;
    std::cin >> coords.oldY >> coords.oldX;
    std::cout << "Pick your move (number, letter):" << std::endl;
    std::cin >> coords.newY >> coords.newX;;
    coords.parseCoords();
    return coords;
}

void Launch() {

    std::cout << "Welcome!" << std::endl;
    std::cout << "Press 'Enter' for start game." << std::endl;
    std::cout << "Press 'Escape' for exit:" << std::endl;
    while (!_kbhit()) {
        GetKeyPressed();
        if (KEY[VK_RETURN]) {
            std::cout << "Go!" << std::endl;
            return;
        } else if (KEY[VK_ESCAPE]) {
            std::cout << "Bye!" << std::endl;
            exit(0);
        }
        std::this_thread::sleep_for(milliseconds(500));
    }

}

void Render(BoardModel *boardModel) {
    BoardView::drawBoard(boardModel);
    std::string player;
    boardModel->getPlayerTurn() == 1 ? player = "BLACK" : player = "WHITE";
    std::cout << "\nBlack pieces: " << boardModel->getBlackCounter() << std::endl;
    std::cout << "White pieces: " << boardModel->getWhiteCounter() << std::endl;
    std::cout << std::endl << "Turn: " + player << std::endl;
}

void Update(Buffer coords, BoardModel *boardModel) {
    BoardController::tryMove(coords.oldY, coords.oldX, coords.newY, coords.newX, boardModel);
}




