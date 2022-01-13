#pragma once

#include "../Model/Figures/IPieceModel.h"


enum MoveType {
    NONE, NORMAL, KILL
};

class MoveStatus {
private:
    MoveType _type;
    IPieceModel *_piece{};

public:
    MoveType getType() const { return _type; }

    IPieceModel *getPiece() const { return this->_piece; }

    MoveStatus(MoveType type) { this->_type = type; }

    MoveStatus(MoveType type, IPieceModel *piece):_type(type), _piece(piece) {}

};

