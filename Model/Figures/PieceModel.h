#pragma once

#include "../../MoveStatus/MoveStatus.h"
#include "../TileModel.h"

#include <iostream>
#include <vector>


class TileModel;

enum Color {
    BLACK = 1, WHITE = -1
};

class PieceModel {
private:
    int _x;
    int _y;
    Color _color;


public:
    PieceModel(int y, int x, Color c);

    virtual ~PieceModel() = default;

    virtual bool isQueen() const = 0;

    void setColor(Color c) { this->_color = c; }

    int getColor() const { return _color; }

    int getY() const { return _y; }

    int getX() const { return _x; }

    void setY(int y) { this->_y = y; }

    void setX(int x) { this->_x = x; }

    virtual MoveStatus move(std::vector<std::vector<TileModel>>, int, int)=0;

};

