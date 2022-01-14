#include "BoardModel.h"


BoardModel *BoardModel::_singleton = nullptr;

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
                auto *piece = Factory::Create("Checker", y, x, Color(-1));
                this->_tiles[y][x].setPiece(piece);
                this->_whiteCounter++;
            }
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 8; x++) {
            if ((y + x) % 2) {
                auto *piece = Factory::Create("Checker", y, x, Color(1));
                this->_tiles[y][x].setPiece(piece);
                this->_blackCounter++;
            }
        }
    }

    _playerTurn = -1;
};

BoardModel *BoardModel::getSingleton() {
    if (_singleton == nullptr) {
        _singleton = new BoardModel();
    }
    return _singleton;
};

bool BoardModel::checkWinCondition() const {

    if (_blackCounter == 0) {
        std::cout << "White player wins" << std::endl;
        return true;
    } else if (_whiteCounter == 0) {
        std::cout << "Black player wins" << std::endl;
        return true;
    } else
        return false;
}

