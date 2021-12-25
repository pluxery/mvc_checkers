#pragma once

#include "../Model/Figures/PieceModel.h"

class PieceModel;

enum MoveType {
    NONE, NORMAL, KILL
};

class MoveStatus {
private:
    MoveType _type;
    PieceModel *_piece{};

public:
    MoveType getType() const;

    PieceModel *getPiece() const;

    MoveStatus(MoveType type);

    MoveStatus(MoveType type, PieceModel *piece);

}

