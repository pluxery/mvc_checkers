#include "CheckerView.h"

void CheckerView::print(PieceModel *p) const {
    if (p->getColor() == Color(1))
        cout << "W ";
    else
        cout << "B ";
}
