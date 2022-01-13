#include "BoardController.h"

void BoardController::tryMove(int oldY, int oldX, int newY, int newX, BoardModel *board) {

    MoveStatus moveStatus = NONE;
    //Проверка корректности координат
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
        //ситуация: ход некорректный
        case NONE:
            break;
            //ситуация: обычный ход
        case NORMAL: {
            IPieceModel *piece = board->getTile(oldY, oldX).getPiece();
            piece->setY(newY);
            piece->setX(newX);
            //Получение королевы
            if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                int color = piece->getColor();
                auto *queen = Factory::Create("Queen", newY, newX, Color(color));
                board->getTile(newY, newX).setPiece(queen);
            } else
                board->getTile(newY, newX).setPiece(piece);
            board->getTile(oldY, oldX).setPiece(nullptr);
            break;
        }
            //ситуация: ход со срубом шашки оппонента
        case KILL:
            IPieceModel *piece = board->getTile(oldY, oldX).getPiece();
            piece->setY(newY);
            piece->setX(newX);

            //Получение королевы
            if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                int color = piece->getColor();
                auto *queen = Factory::Create("Queen", newY, newX, Color(color));
                board->getTile(newY, newX).setPiece(queen);
            } else
                board->getTile(newY, newX).setPiece(piece);

            board->getTile(oldY, oldX).setPiece(nullptr);

            IPieceModel *otherPiece = moveStatus.getPiece();
            board->getTile(otherPiece->getY(), otherPiece->getX()).setPiece(nullptr);

            if (piece->getColor() == 1)
                board->decrementWhiteCounter();
            else
                board->decrementBlackCounter();

            break;
    }
}


