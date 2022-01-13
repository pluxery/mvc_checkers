#include "Game.h"

void Position::ParseCoords() { //char to int
    int numbers[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int code = 48, digit = 0; code < 58; code++, digit++) {
        if (this->oldY == code) {
            this->oldY = numbers[digit];
        }
        if (this->newY == code) {
            this->newY = numbers[digit];
        }
    }
    this-> oldY--;
    this->newY--;

    for (int code = 65, letter = 0; code < 73; code++, letter++) {
        if (this->oldX == code) {
            this->oldX = numbers[letter];
        }
        if (this->newX == code) {
            this->newX = numbers[letter];
        }
    }
}

Position& Position::operator=(const std::vector<char> &buffer) {
    this->oldY = buffer[0];
    this->oldX = buffer[1];
    this->newY = buffer[2];
    this->newX = buffer[3];
    return  *this;
}


Position Input(Position &coords) {
    std::vector<char> buffer;

    std::cin.ignore();
    std::cout << "Pick your piece (number, letter): " << std::endl;
    //_getch() - Считывание клавиши с клавиатуры
    buffer.push_back(_getch());
    buffer.push_back(_getch());

    std::cin.ignore();
    std::cout << "Pick your move (number, letter): " << std::endl;
    buffer.push_back(_getch());
    buffer.push_back(_getch());

    coords = buffer;
    coords.ParseCoords();
    return coords;

}

void Launch() {

    std::cout << ("Welcome!\n");
    std::cout << ("Press '1' for start game. \nPress any key for exit:\n");
    std::cout << ("Press 'Escape' during the game to exit\n");
    int input_key;
    input_key = _getch();
    if (input_key == '1') {
        std::cout << ("Go!\n");
        return;
    }
    std::cout << ("\nBye!\n");
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

void AsyncExitListener() {
    while (true) {
        GetKeyPressed();
        if (KEY[VK_ESCAPE]) {
            std::cout << "Bye!" << std::endl;
            exit(0);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
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



