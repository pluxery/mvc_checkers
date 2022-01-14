#pragma once

#include "../Model/BoardModel.h"
#include "../Controller/BoardController.h"
#include "../Controller/BoardController.cpp"


class BoardView {
public:
    static void drawBoard(BoardModel *board);
};



