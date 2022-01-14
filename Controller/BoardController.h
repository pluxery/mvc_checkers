#pragma once

#include "../Model/BoardModel.h"
#include "../Model/BoardModel.cpp"
#include "../Model/Figures/IPieceModel.h"
#include "../MoveState/MoveState.h"

//#include "../Model/Figures/CheckerModel.cpp"


const char row[] = "ABCDEFGH";

class BoardController {
public:
     static void tryMove(int oldY, int oldX, int newY, int newX, BoardModel *board);
};

