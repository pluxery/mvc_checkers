#pragma once


#include<vector>
#include "PieceModel.h"


class CheckerModel : public PieceModel {
    using PieceModel::PieceModel;

public:
    ~CheckerModel() override = default;

    MoveStatus move(const std::vector<std::vector<TileModel>> &tiles, int newY, int newX) override;
};






