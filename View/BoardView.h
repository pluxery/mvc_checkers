#pragma once

#include "../Model/BoradModel.h"
#include "Figures/QueenView.h"
#include "Figures/CheckerView.h"
#include "../Model/BoradModel.h"
#include "../Model/Figures/QueenModel.h"
#include "../Model/Figures/CheckerModel.h"
#include "../Model/Figures/PieceModel.h"
#include "../Controller/BoardController.h"



class BoardView {
public:
    static void printBoard(BoardModel *board){
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
            std::cout << std::endl;
        }
        std::cout << "  ";

        for (int x = 0; x < 8; x++) {
            std::cout << row[x] << " ";
        }
    };
};



