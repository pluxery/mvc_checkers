#pragma once


#include "Figures/PieceModel.h"

class PieceModel;


class TileModel {
private:
    PieceModel *_piece;

public:
    TileModel() { this->_piece = nullptr; };

    void setPiece(PieceModel *piece) { _piece = piece; };

    PieceModel *getPiece() const { return _piece; };

    bool hasPiece() const { return this->_piece != nullptr; }
};

