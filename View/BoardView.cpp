#include "BoardView.h"

void BoardView::printBoard(BoardModel *board) {
    for (int y = 0; y < 8; y++) {
        std::cout << y + 1 << " ";
        for (int x = 0; x < 8; x++) {
            if (board->getTile(y, x).hasPiece()) {
                auto *p = board->getTile(y, x).getPiece();
                if (p->isQueen()) {
                    QueenView q;
                    q.print(p);
                } else {
                    CheckerView c;
                    c.print(p);
                }

            } else if (!board->getTile(y, x).hasPiece() && (x + y) % 2)
                std::cout << ". ";
            else
                std::cout << "  ";
        }
        std::cout << endl;
    }
    std::cout << "  ";

    for (int x = 0; x < 8; x++) {
        std::cout << row[x] << " ";
    }
}

