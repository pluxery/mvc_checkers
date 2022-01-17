#pragma once

#include "../Figures/IPieceModel.h"


enum MoveType {
    NONE, NORMAL, KILL
};

class MoveState {
private:
    MoveType _type;
    IPieceModel *_piece{};

public:
    MoveType getType() const { return _type; }

    IPieceModel *getPiece() const { return this->_piece; }

    MoveState(MoveType type) : _type(type) {};

    MoveState(MoveType type, IPieceModel *piece) : _type(type), _piece(piece) {}

};

