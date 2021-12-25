#include "BoradModel.h"

BoardModel::BoardModel() {
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
}

bool BoardModel::checkWinCondition() const {

    if (_blackCounter == 0) {
        cout << "White player wins" << endl;
        return true;
    } else if (_whiteCounter == 0) {
        cout << "Black player wins" << endl;
        return true;
    } else
        return false;
}