#ifndef MVC_CHECKERS_QUEENMODEL_H
#define MVC_CHECKERS_QUEENMODEL_H
#include "PieceModel.h"
#include<iostream>
#include <vector>
using namespace std;

class PieceModel;

class QueenModel : public PieceModel {
    using PieceModel::PieceModel;
public:
    ~QueenModel() override = default;

    bool isQueen() const override { return true; };

    MoveStatus move(vector<vector<TileModel>> tiles, int newY, int newX) override;

    static PieceModel *checkDiagonal(const vector<vector<TileModel>> &tiles, int oldY, int oldX, int newY, int newX);

};


#endif //MVC_CHECKERS_QUEENMODEL_H
