#include "CheckerModel.h"

MoveStatus CheckerModel::move(const std::vector<std::vector<TileModel>> &tiles, int newY, int newX) {
    if (tiles[newY][newX].hasPiece() || (newY + newX) % 2 == 0) {
        return {NONE};
    }
    int y0 = this->getY();
    int x0 = this->getX();
    //проверка обычного хода
    if (newY - y0 == (int) (this->getColor()) && abs(newX - x0) == 1) {
        return {NORMAL};
        //проверка хода со срезом шашки
    } else if (newY - y0 == (int) (this->getColor()) * 2 && abs(newX - x0) == 2) {
        int other_y = y0 + (newY - y0) / 2;
        int other_x = x0 + (newX - x0) / 2;
        if (tiles[other_y][other_x].hasPiece() &&
            tiles[other_y][other_x].getPiece()->getColor() != this->getColor()) {
            return {KILL, tiles[other_y][other_x].getPiece()};
        }
    }
    return {NONE};

}
