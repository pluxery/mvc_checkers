#include "QueenView.h"

void QueenView::print(PieceModel *p) const  {
    if (p->getColor() == Color(-1))
        cout << "W ";
    else
        cout << "B ";
}
