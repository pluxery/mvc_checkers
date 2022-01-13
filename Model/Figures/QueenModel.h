#pragma once


#include "IPieceModel.h"


class QueenModel : public IPieceModel {
    using IPieceModel::IPieceModel;
public:
    ~QueenModel() override = default;

    static IPieceModel *
    checkDiagonal(const std::vector<std::vector<TileModel>> &tiles, int oldY, int oldX, int newY, int newX);

    MoveState move(const std::vector<std::vector<TileModel>> &tiles, int newY, int newX) override;


};



