#pragma once
#include "../Model/BoradModel.h"
#include "../MoveStatus/MoveStatus.h"
#include "../Model/Figures/PieceModel.h"
#include <vector>
#include "../Model/TileModel.h"

const char row[] = "ABCDEFGH";
class BoardModel;
class PieceModel;
class MoveStatus;
class TileModel;
class BoardController {
public:
    static void tryMove(int old_number, char old_letter, int new_number, char new_letter, BoardModel *board);
};
