#pragma once
#include "PieceView.h"
#include "../../Model/Figures/PieceModel.h"


class PieceModel;
class CheckerView : public PieceView {
public:
    void print(PieceModel *p) const override;
};

