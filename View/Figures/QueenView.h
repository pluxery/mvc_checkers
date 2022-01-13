#pragma once

#include "IPieceView.h"


class QueenView : public IPieceView {
public:
    void Update(Subject *subject) const override {
        if (subject->getColor() == Color(-1))
            std::cout << "W ";
        else
            std::cout << "B ";
    }
};


