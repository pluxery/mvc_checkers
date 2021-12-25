
#include "TileModel.h"

TileModel::TileModel() {
    this->_piece = nullptr;

}

void TileModel::setPiece(PieceModel *piece) { _piece = piece; }

PieceModel *TileModel::getPiece() const { return _piece; }

bool TileModel::hasPiece() const { return this->_piece != nullptr; }
