#pragma once
#include "../../Model/Figures/PieceModel.h"

class PieceModel;

class PieceView {
public:
    virtual void print(PieceModel *p) const = 0;

};



