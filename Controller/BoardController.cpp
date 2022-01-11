#include "BoardController.h"

void BoardController::tryMove(int old_number, char old_letter, int new_number, char new_letter, BoardModel *board) {

    //Преобразование координат для доски
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
            PieceModel *piece = board->getTile(oldY, oldX).getPiece();
            piece->setY(newY);
            piece->setX(newX);
            //Получение королевы
            if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                //Создаем Subject (QueenModel) с наблюдателем (QueenView : Observer)
                int color = piece->getColor();
                auto *queen = new QueenModel(newY, newX, Color(color));
                const auto queenObserver = new QueenView();
                queen->Attach(queenObserver);

                board->getTile(newY, newX).setPiece(queen);
            } else
                board->getTile(newY, newX).setPiece(piece);
            board->getTile(oldY, oldX).setPiece(nullptr);
            break;
        }
            //ситуация: ход со срубом шашки оппонента
        case KILL:
            PieceModel *piece = board->getTile(oldY, oldX).getPiece();
            piece->setY(newY);
            piece->setX(newX);
            //Получение королевы
            if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                //Создаем Subject (QueenModel) с наблюдателем (QueenView : Observer)
                int color = piece->getColor();
                auto *queen = new QueenModel(newY, newX, Color(color));
                const auto queenObserver = new QueenView();
                queen->Attach(queenObserver);
                board->getTile(newY, newX).setPiece(queen);
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
}


