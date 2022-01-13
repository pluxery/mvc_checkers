#pragma once


#include "Figures/IPieceModel.h"

class IPieceModel;


class TileModel {
private:
    IPieceModel *_piece;

public:
    TileModel() { this->_piece = nullptr; };

    void setPiece(IPieceModel *piece) { _piece = piece; };

    IPieceModel *getPiece() const { return _piece; };

    bool hasPiece() const { return this->_piece != nullptr; }
};

