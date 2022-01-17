#include "BoardView.h"

void BoardView::drawBoard(BoardModel *board) {
    for (int y = 0; y < 8; y++) {
        std::cout << y + 1 << " ";
        for (int x = 0; x < 8; x++) {
            if (board->getTile(y, x).hasPiece()) {
                auto *piece = board->getTile(y, x).getPiece();
                piece->Notify();

            } else if (!board->getTile(y, x).hasPiece() && (x + y) % 2)
                std::cout << ". ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";

    for (int x = 0; x < 8; x++) {
        std::cout << row[x] << " ";
    }
}
