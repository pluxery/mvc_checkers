#pragma once


#include "PieceModel.h"


class QueenModel : public PieceModel {
    using PieceModel::PieceModel;
public:
    ~QueenModel() override = default;

    static PieceModel *
    checkDiagonal(const std::vector<std::vector<TileModel>> &tiles, int oldY, int oldX, int newY, int newX);

    MoveStatus move(const std::vector<std::vector<TileModel>> &tiles, int newY, int newX) override;


};



