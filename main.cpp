#include <iostream>
#include "Model/BoardModel.h"
#include "Game/Game.h"
#include "Game/Game.cpp"

int main() {

    Launch();

    auto *board = BoardModel::getSingleton();

    std::thread async_exit(AsyncExitListener);
    async_exit.detach();

    using clock = std::chrono::steady_clock;
    const int FPS = 60;

    while (!board->checkWinCondition()) {

        Render(board);
        Buffer coords{};
        Input(coords);
        Update(coords, board);

        auto frame = (clock::now() += milliseconds(1000 / FPS)); // = 16ms;
        std::this_thread::sleep_until(frame);
    }
}



