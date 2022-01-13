#include <iostream>
#include "Model/BoardModel.h"
#include "Game/Game.h"
#include "Game/Game.cpp"

using namespace std;

int main() {

    Launch();

    auto *boardModel = BoardModel::GetSingleton();

    auto frame = std::chrono::steady_clock::now();
    const int FPS = 60;

    std::thread async_exit(AsyncExitListener);
    async_exit.detach();

    while (!boardModel->checkWinCondition()) {

        Render(boardModel);
        Position coords{};
        Input(coords);
        Update(coords, boardModel);

        frame += std::chrono::milliseconds(1000 / FPS); // = 16ms
        std::this_thread::sleep_until(frame);
    }
}



