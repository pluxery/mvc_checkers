#pragma once
#include "PieceView.h"

class PieceView;

class CheckerView : public PieceView {
public:
    void print(PieceModel *p) const override{
        if (p->getColor() == Color(1))
            std::cout << "W ";
        else
           std::cout << "B ";
    };
};

