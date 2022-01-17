#include "BoardController.h"

void BoardController::tryMove(int oldY, int oldX, int newY, int newX, BoardModel *board) {

    MoveState move_state = NONE;

    if (board->getTile(oldY, oldX).hasPiece() && !board->getTile(newY, newX).hasPiece() &&
        board->getPlayerTurn() == board->getTile(oldY, oldX).getPiece()->getColor()) {

        move_state = board->getTile(oldY, oldX).getPiece()->move(board->getBoardTiles(), newY, newX);

        if (move_state.getType() != NONE) {
            if (board->getPlayerTurn() == 1)
                board->setPlayerTurn(-1);
            else
                board->setPlayerTurn(1);
        } else {
            std::cerr << "Wrong position!" << std::endl;
        }
    }

    switch (move_state.getType()) {

        case NONE:
            break;

        case NORMAL: {
            IPieceModel *piece = board->getTile(oldY, oldX).getPiece();
            piece->setY(newY);
            piece->setX(newX);

            if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                int color = piece->getColor();
                auto *queen = BoardModel::createPiece("Queen", newY, newX, Color(color));
                board->getTile(newY, newX).setPiece(queen);
            } else
                board->getTile(newY, newX).setPiece(piece);
            board->getTile(oldY, oldX).setPiece(nullptr);
            break;
        }

        case KILL:
            IPieceModel *piece = board->getTile(oldY, oldX).getPiece();
            piece->setY(newY);
            piece->setX(newX);


            if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                int color = piece->getColor();
                auto *queen = BoardModel::createPiece("Queen", newY, newX, Color(color));
                board->getTile(newY, newX).setPiece(queen);
            } else
                board->getTile(newY, newX).setPiece(piece);

            board->getTile(oldY, oldX).setPiece(nullptr);

            IPieceModel *otherPiece = move_state.getPiece();
            board->getTile(otherPiece->getY(), otherPiece->getX()).setPiece(nullptr);

            if (piece->getColor() == 1)
                board->decrementWhiteCounter();
            else
                board->decrementBlackCounter();

            break;
    }
}


