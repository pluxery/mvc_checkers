#pragma once

#include "../Model/BoardModel.h"
#include "../Model/BoardModel.cpp"
#include "../Model/Figures/IPieceModel.h"
#include "../MoveStatus/MoveStatus.h"

//#include "../Model/Figures/CheckerModel.cpp"


const char row[] = "ABCDEFGH";

class BoardController {
public:
     static void tryMove(int old_number, int old_letter, int new_number, int new_letter, BoardModel *board);
};

