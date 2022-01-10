#pragma once


#include<vector>
#include "PieceModel.h"


class CheckerModel : public PieceModel {
    using PieceModel::PieceModel;

public:
    ~CheckerModel() override = default;

    MoveStatus move(std::vector<std::vector<TileModel>> tiles, int newY, int newX) override;
};


MoveStatus CheckerModel::move(std::vector<std::vector<TileModel>> tiles, int newY, int newX)  {
    if (tiles[newY][newX].hasPiece() || (newY + newX) % 2 == 0) {
        return {NONE};
    }
    int y0 = this->getY();
    int x0 = this->getX();
    if (newY - y0 == (int) (this->getColor()) && abs(newX - x0) == 1) {
        return {NORMAL};
    } else if (newY - y0 == (int) (this->getColor()) * 2 && abs(newX - x0) == 2) {
        int other_y = y0 + (newY - y0) / 2;
        int other_x = x0 + (newX - x0) / 2;
        if (tiles[other_y][other_x].hasPiece() &&
            tiles[other_y][other_x].getPiece()->getColor() != this->getColor()) {
            return {KILL, tiles[other_y][other_x].getPiece()};
        }
    }
    return {NONE};

}


