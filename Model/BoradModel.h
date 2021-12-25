#pragma once
#include "TileModel.h"
#include <vector>
#include "Figures/CheckerModel.h"
#include "Figures/QueenModel.h"
#include "Figures/PieceModel.h"

using namespace std;

class CheckerModel;
class QueenModel;
class PieceModel;
class TileModel;


class BoardModel {
private:
    mutable vector<vector<TileModel>> _tiles;
    int _blackCounter;
    int _whiteCounter;
    int _playerTurn;
public:
    BoardModel();

    bool checkWinCondition() const;

    int getWhiteCounter() const { return _whiteCounter; }

    int getBlackCounter() const { return _blackCounter; }

    int decrementWhiteCounter() { return --_whiteCounter; }

    int decrementBlackCounter() { return --_blackCounter; }

    TileModel &getTile(int y, int x) const { return _tiles[y][x]; }

    int getPlayerTurn() const { return _playerTurn; }

    void setPlayerTurn(int value) { _playerTurn = value; }

    vector<vector<TileModel>> &getBoardTiles() { return _tiles; };

};
