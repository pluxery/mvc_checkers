#pragma once

#include<vector>
#include "../TileModel.h"
#include "../../MoveStatus/MoveStatus.h"
#include "../../Observer/Observer.h"


enum Color {
    BLACK = 1, WHITE = -1
};

class PieceModel : public Subject {
private:
    int _x;
    int _y;
    Color _color;


public:
    PieceModel(int y, int x, Color c) {
        this->_x = x;
        this->_y = y;
        this->_color = c;

    };

    virtual ~PieceModel() = default;

    int getColor() const override { return _color; }

    int getY() const { return _y; }

    int getX() const { return _x; }

    void setY(int y) { this->_y = y; }

    void setX(int x) { this->_x = x; }

    virtual MoveStatus move(std::vector<std::vector<TileModel>>, int, int) = 0;

};

