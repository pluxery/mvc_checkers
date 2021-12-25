#pragma once
#include "PieceModel.h"
#include "../../MoveStatus/MoveStatus.h"
#include <vector>
#include <iostream>

using namespace std;

class PieceModel;
class MoveStatus;

class CheckerModel : public PieceModel {
    using PieceModel::PieceModel;

public:
    bool isQueen() const override { return false; };

    ~CheckerModel() override = default;

    MoveStatus move(vector<vector<TileModel>> tiles, int newY, int newX) override;
};

