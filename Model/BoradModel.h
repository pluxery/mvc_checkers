#pragma once

#include <vector>
#include "Figures/CheckerModel.h"
#include "TileModel.h"


class TileModel;

class BoardModel {
private:
    mutable std::vector<std::vector<TileModel>> _tiles;
    int _blackCounter;
    int _whiteCounter;
    int _playerTurn;
public:
    BoardModel(){
        for (int y = 0; y < 8; y++) {
            std::vector<TileModel> v1;
            v1.reserve(8);
            for (int x = 0; x < 8; x++) {
                v1.emplace_back();
            }
            _tiles.push_back(v1);
        }

        this->_whiteCounter = 0;
        this->_blackCounter = 0;

        for (int y = 5; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if ((y + x) % 2) {
                    this->_tiles[y][x].setPiece(new CheckerModel(y, x, Color(-1)));
                    this->_whiteCounter++;
                }
            }
        }

        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 8; x++) {
                if ((y + x) % 2) {
                    this->_tiles[y][x].setPiece(new CheckerModel(y, x, Color(1)));
                    this->_blackCounter++;
                }
            }
        }

        _playerTurn = -1;
    };

    bool checkWinCondition() const{

        if (_blackCounter == 0) {
            std::cout << "White player wins" << std::endl;
            return true;
        } else if (_whiteCounter == 0) {
            std::cout << "Black player wins" << std::endl;
            return true;
        } else
            return false;
    };

    int getWhiteCounter() const { return _whiteCounter; }

    int getBlackCounter() const { return _blackCounter; }

    int decrementWhiteCounter() { return --_whiteCounter; }

    int decrementBlackCounter() { return --_blackCounter; }

    TileModel &getTile(int y, int x) const { return _tiles[y][x]; }

    int getPlayerTurn() const { return _playerTurn; }

    void setPlayerTurn(int value) { _playerTurn = value; }

    std::vector<std::vector<TileModel>> &getBoardTiles() { return _tiles; };

};
