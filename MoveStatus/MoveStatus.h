#pragma once

#include "../Model/Figures/PieceModel.h"


enum MoveType {
    NONE, NORMAL, KILL
};

class MoveStatus {
private:
    MoveType _type;
    PieceModel *_piece{};

public:
    MoveType getType() const { return _type; }

    PieceModel *getPiece() const { return this->_piece; }

    MoveStatus(MoveType type) { this->_type = type; }

    MoveStatus(MoveType type, PieceModel *piece) {
        this->_type = type;
        this->_piece = piece;
    }

};

