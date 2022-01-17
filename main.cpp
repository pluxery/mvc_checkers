#include <iostream>
#include "Model/BoardModel/BoardModel.h"
#include "Game/Game.h"
#include "Game/Game.cpp"

int main() {

    Launch();
    auto *board = BoardModel::getInstance();

    std::thread async_exit(AsyncExitListener);
    async_exit.detach();

    while (!board->checkWinCondition()) {
        Render(board);
        Buffer coords{};
        Input(coords);
        Update(coords, board);
    }
}



