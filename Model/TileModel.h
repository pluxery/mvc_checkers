
#pragma once
#include "./Figures/PieceModel.h"
#include<iostream>

using namespace std;

class PieceModel;

class TileModel {
private:
    PieceModel *_piece;
public:
    TileModel();

    void setPiece(PieceModel *piece);

    PieceModel *getPiece() const;

    bool hasPiece() const;
};

