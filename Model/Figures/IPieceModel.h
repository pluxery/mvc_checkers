#pragma once

#include<vector>
#include "../TileModel.h"
#include "../../MoveState/MoveState.h"
#include "../../Observer/Observer.h"


enum Color {
    BLACK = 1, WHITE = -1
};

class IPieceModel : public Subject {
private:
    int _x;
    int _y;
    Color _color;

public:
    IPieceModel(int y, int x, Color c) : _y(y), _x(x), _color(c) {};

    virtual ~IPieceModel() = default;

    int getColor() const override { return _color; }

    int getY() const { return _y; }

    int getX() const { return _x; }

    void setY(int y) { this->_y = y; }

    void setX(int x) { this->_x = x; }

    virtual MoveState move(const std::vector<std::vector<TileModel>> &tiles, int newY, int newX) = 0;

};


