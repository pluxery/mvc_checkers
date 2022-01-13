#pragma once


#include<vector>
#include "IPieceModel.h"


class CheckerModel : public IPieceModel {
    using IPieceModel::IPieceModel;

public:
    ~CheckerModel() override = default;

    MoveStatus move(const std::vector<std::vector<TileModel>> &tiles, int newY, int newX) override;
};






