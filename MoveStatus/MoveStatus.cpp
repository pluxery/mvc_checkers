#include "MoveStatus.h"

MoveType MoveStatus::getType() const { return _type; }

PieceModel *MoveStatus::getPiece() const { return this->_piece; };

MoveStatus::MoveStatus(MoveType type) {
    this->_type = type;

}

MoveStatus::MoveStatus(MoveType type, PieceModel *piece) {
    this->_type = type;
    this->_piece = piece;

}
