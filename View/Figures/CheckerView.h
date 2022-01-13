#pragma once

#include "IPieceView.h"


class CheckerView : public IPieceView {
public:
    void Update(Subject *subject) const override {
        if (subject->getColor() == Color(-1))
            std::cout << "w ";
        else
            std::cout << "b ";
    }

};

