#include <iostream>
#include "Model/BoardModel.h"
#include "Game/Game.h"
#include "Game/Game.cpp"

using namespace std;

int main() {

    Launch();

    auto *boardModel = BoardModel::GetSingleton();

    std::thread async_exit(AsyncExitListener);
    async_exit.detach();

    using clock = std::chrono::steady_clock;
    const int FPS = 60;

    while (!boardModel->checkWinCondition()) {

        Render(boardModel);
        Position coords{};
        Input(coords);
        Update(coords, boardModel);

        auto frame = (clock::now() += ms(1000 / FPS)); // = 16ms;
        std::this_thread::sleep_until(frame);
    }
}



