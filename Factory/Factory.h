#pragma once

#include<string>

#include "../Model/Figures/CheckerModel.h"
#include "../Model/Figures/QueenModel.h"
#include "../View/Figures/CheckerView.h"
#include "../View/Figures/QueenView.h"


class Factory {
public:
    static IPieceModel *Create(const std::string &model, const int &y, const int &x, Color color);
};


