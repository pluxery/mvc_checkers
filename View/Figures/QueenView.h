#pragma once
#include "PieceView.h"
#include <iostream>
using namespace std;

class QueenView : public PieceView {
public:
    void print(PieceModel *p) const override;
};


