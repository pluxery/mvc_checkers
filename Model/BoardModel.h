#pragma once

#include <vector>
#include "Figures/CheckerModel.h"
#include "Figures/CheckerModel.cpp"
#include "Figures/QueenModel.h"
#include "Figures/QueenModel.cpp"
#include "../View/Figures/CheckerView.h"
#include "../View/Figures/QueenView.h"
#include "../Factory/Factory.h"
#include "../Factory/Factory.cpp"


class BoardModel {
private:
    mutable std::vector<std::vector<TileModel>> _tiles;
    int _blackCounter;
    int _whiteCounter;
    int _playerTurn;

protected:
    /*
     * Конструктор Singleton должен быть скрытым, чтобы предотвратить
     * создание объекта через оператор new.
     */
    BoardModel();

    static BoardModel *singleton_;

public:
    BoardModel(BoardModel &other) = delete;//Singleton нельзя копировать

    void operator=(const BoardModel &) = delete;

    static BoardModel *GetSingleton();

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

