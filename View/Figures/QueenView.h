#pragma once

#include "PieceView.h"


class QueenView : public PieceView {
public:
    void Update(Subject *subject) const override {
        if (subject->getColor() == Color(-1))
            std::cout << "W ";
        else
            std::cout << "B ";
    }
};


