#pragma once

#include "PieceView.h"


class CheckerView : public PieceView {
public:
    void Update(Subject *subject) const override {
        if (subject->getColor() == Color(-1))
            std::cout << "w ";
        else
            std::cout << "b ";
    }

};

