#pragma once

#include "../Model/BoradModel.h"
#include "../Model/Figures/PieceModel.h"
#include "../MoveStatus/MoveStatus.h"
#include "../Model/Figures/QueenModel.h"
#include "../Model/Figures/CheckerModel.h"

class BoardModel;
class PieceModel;


const char row[] = "ABCDEFGH";

class BoardController {
public:
     static void tryMove(int old_number, char old_letter, int new_number, char new_letter, BoardModel *board){
         int oldY = old_number - 1, oldX = 0;
         int newY = new_number - 1, newX = 0;
         int j = 0;
         for (char i: row) {
             if (i == old_letter)
                 oldX = j;
             ++j;
         }
         j = 0;
         for (char i: row) {
             if (i == new_letter)
                 newX = j;
             ++j;
         }

         MoveStatus moveStatus = NONE;

         if (board->getTile(oldY, oldX).hasPiece() && !board->getTile(newY, newX).hasPiece() &&
             board->getPlayerTurn() == board->getTile(oldY, oldX).getPiece()->getColor()) {
             moveStatus = board->getTile(oldY, oldX).getPiece()->move(board->getBoardTiles(), newY, newX);
             if (moveStatus.getType() != NONE) {
                 if (board->getPlayerTurn() == 1)
                     board->setPlayerTurn(-1);
                 else
                     board->setPlayerTurn(1);
             } else {
                 std::cout << "Wrong position!" << std::endl;
             }
         }

         switch (moveStatus.getType()) {

             case NONE:
                 break;
             case NORMAL: {
                 PieceModel *piece = board->getTile(oldY, oldX).getPiece();
                 piece->setY(newY);
                 piece->setX(newX);
                 std::cout << piece->getX() << std::endl;
                 if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                     int color = piece->getColor();
                     board->getTile(newY, newX).setPiece(new QueenModel(newY, newX, Color(color)));
                 } else
                     board->getTile(newY, newX).setPiece(piece);
                 std::cout << oldX << " " << oldY;
                 board->getTile(oldY, oldX).setPiece(nullptr);
                 break;
             }

             case KILL:
                 PieceModel *piece = board->getTile(oldY, oldX).getPiece();
                 piece->setY(newY);
                 piece->setX(newX);
                 if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                     int color = piece->getColor();
                     board->getTile(newY, newX).setPiece(new QueenModel(newY, newX, Color(color)));
                 } else
                     board->getTile(newY, newX).setPiece(piece);
                 board->getTile(oldY, oldX).setPiece(nullptr);

                 PieceModel *otherPiece = moveStatus.getPiece();
                 board->getTile(otherPiece->getY(), otherPiece->getX()).setPiece(nullptr);

                 if (piece->getColor() == 1)
                     board->decrementWhiteCounter();
                 else
                     board->decrementBlackCounter();

                 break;
         }
     };;
};
