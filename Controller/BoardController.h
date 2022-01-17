#pragma once

#include "../Model/BoardModel/BoardModel.h"
#include "../Model/BoardModel/BoardModel.cpp"
#include "../Model/Figures/IPieceModel.h"
#include "../Model/MoveState/MoveState.h"


const char row[] = "ABCDEFGH";

class BoardController {
public:
     static void tryMove(int oldY, int oldX, int newY, int newX, BoardModel *board);
};

