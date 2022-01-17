#pragma once

#include <vector>
#include "../Figures/CheckerModel.h"
#include "../Figures/CheckerModel.cpp"
#include "../Figures/QueenModel.h"
#include "../Figures/QueenModel.cpp"
#include "../../View/Figures/CheckerView.h"
#include "../../View/Figures/QueenView.h"


class BoardModel {
private:
    mutable std::vector<std::vector<TileModel>> _tiles;
    int _blackCounter;
    int _whiteCounter;
    int _playerTurn;

protected:
    BoardModel();

    static BoardModel *_instance;

public:
    BoardModel(const BoardModel &) = delete;

    BoardModel(BoardModel &&) = delete;

    BoardModel &operator=(const BoardModel &) = delete;

    BoardModel &operator=(BoardModel &&) = delete;

    static BoardModel *getInstance();

    static IPieceModel *createPiece(const std::string &model, const int &y, const int &x, Color color);

    bool checkWinCondition() const;

    int decrementWhiteCounter() { return --_whiteCounter; }

    int decrementBlackCounter() { return --_blackCounter; }

    TileModel &getTile(int y, int x) const { return _tiles[y][x]; }

    int getPlayerTurn() const { return _playerTurn; }

    void setPlayerTurn(int value) { _playerTurn = value; }

    std::vector<std::vector<TileModel>> &getBoardTiles() { return _tiles; }

    int getWhiteCounter() const { return _whiteCounter; }

    int getBlackCounter() const { return _blackCounter; }

};

