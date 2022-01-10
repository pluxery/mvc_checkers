#include <iostream>
#include "Model/BoradModel.h"
#include "Game/Game.h"
#include <ctime>
#include <chrono>
#include <thread>


int main() {

    auto *boardModel = new BoardModel();

    using clock = std::chrono::steady_clock;
    auto frame = clock::now();
    const size_t FPS = 60;


    while (!boardModel->checkWinCondition()) {

        frame += std::chrono::milliseconds(1000 / FPS);

        Render(boardModel);
        Position pos{};
        Input(pos);
        Update(pos, boardModel);

        std::this_thread::sleep_until(frame);
    }

}


