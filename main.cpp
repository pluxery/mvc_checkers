#include <iostream>
#include<vector>

using namespace std;

class MoveStatus;

class TileModel;

class PieceModel;

class BoardModel;

enum Color {
    BLACK = 1, WHITE = -1
};
enum MoveType {
    NONE, NORMAL, KILL
};

class MoveStatus {
private:
    MoveType _type;
    PieceModel *_piece{};

public:
    MoveType getType() const { return _type; }

    PieceModel *getPiece() const { return this->_piece; };

    MoveStatus(MoveType type) { this->_type = type; };

    MoveStatus(MoveType type, PieceModel *piece) {
        this->_type = type;
        this->_piece = piece;
    };
};

const char row[] = "ABCDEFGH";

//HOMEWORK #2 --- MVC
class PieceModel {
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

    virtual bool isQueen() const = 0;

    void setColor(Color c) { this->_color = c; }

    int getColor() const { return _color; }

    int getY() const { return _y; }

    int getX() const { return _x; }

    void setY(int y) { this->_y = y; }

    void setX(int x) { this->_x = x; }

    virtual MoveStatus move(vector<vector<TileModel>> tiles, int, int) = 0;

};

class PieceView {
public:
    virtual void print(PieceModel *p) const = 0;

};

class CheckerModel : public PieceModel {
    using PieceModel::PieceModel;

public:
    bool isQueen() const override { return false; };

    ~CheckerModel() override = default;

    MoveStatus move(vector<vector<TileModel>> tiles, int newY, int newX) override;
};

class CheckerView : public PieceView {
public:
    void print(PieceModel *p) const override {
        if (p->getColor() == Color(-1))
            cout << "w ";
        else
            cout << "b ";
    }
};

class QueenModel : public PieceModel {
    using PieceModel::PieceModel;
public:
    ~QueenModel() override = default;

    bool isQueen() const override { return true; };

    MoveStatus move(vector<vector<TileModel>> tiles, int newY, int newX) override;

    static PieceModel *checkDiagonal(const vector<vector<TileModel>> &tiles, int oldY, int oldX, int newY, int newX);

};

class QueenView : public PieceView {
public:
    void print(PieceModel *p) const override {
        if (p->getColor() == Color(-1))
            cout << "W ";
        else
            cout << "B ";
    }
};

class TileModel {
private:
    PieceModel *_piece;
public:
    TileModel() { this->_piece = nullptr; }

    void setPiece(PieceModel *piece) { _piece = piece; }

    PieceModel *getPiece() const { return _piece; }

    bool hasPiece() const { return this->_piece != nullptr; }
};

class BoardModel {
private:
    mutable vector<vector<TileModel>> _tiles;
    int _blackCounter;
    int _whiteCounter;
    int _playerTurn;
public:
    BoardModel() {
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

    bool checkWinCondition() const {

        if (_blackCounter == 0) {
            cout << "White player wins" << endl;
            return true;
        } else if (_whiteCounter == 0) {
            cout << "Black player wins" << endl;
            return true;
        } else
            return false;

    }

    int getWhiteCounter() const { return _whiteCounter; }

    int getBlackCounter() const { return _blackCounter; }

    int decrementWhiteCounter() { return --_whiteCounter; }

    int decrementBlackCounter() { return --_blackCounter; }

    TileModel &getTile(int y, int x) const { return _tiles[y][x]; }

    int getPlayerTurn() const { return _playerTurn; }

    void setPlayerTurn(int value) { _playerTurn = value; }

    vector<vector<TileModel>> &getBoardTiles() { return _tiles; };

};

class BoardView {
public:
    static void printBoard(BoardModel *board) {
        for (int y = 0; y < 8; y++) {
            cout << y + 1 << " ";
            for (int x = 0; x < 8; x++) {
                if (board->getTile(y, x).hasPiece()) {
                    auto *p = board->getTile(y, x).getPiece();
                    if (p->isQueen()) {
                        QueenView q;
                        q.print(p);
                    } else {
                        CheckerView c;
                        c.print(p);
                    }

                } else if (!board->getTile(y, x).hasPiece() && (x + y) % 2)
                    cout << ". ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
        cout << "  ";

        for (int x = 0; x < 8; x++) {
            cout << row[x] << " ";
        }
    }


};

class BoardController {
public:
    static void tryMove(int old_number, char old_letter, int new_number, char new_letter, BoardModel *board) {
        int oldY = old_number - 1, oldX = 0;
        int newY = new_number - 1, newX = 0;
        int j = 0;
        for (char i: row) {
            if (i == old_letter)
                oldX = j;
            ++j;
        }
        j = 0;
        for (char i: row) {
            if (i == new_letter)
                newX = j;
            ++j;
        }

        MoveStatus moveStatus = NONE;

        if (board->getTile(oldY, oldX).hasPiece() && !board->getTile(newY, newX).hasPiece() &&
            board->getPlayerTurn() == board->getTile(oldY, oldX).getPiece()->getColor()) {
            moveStatus = board->getTile(oldY, oldX).getPiece()->move(board->getBoardTiles(), newY, newX);
            if (moveStatus.getType() != NONE) {
                if (board->getPlayerTurn() == 1)
                    board->setPlayerTurn(-1);
                else
                    board->setPlayerTurn(1);
            } else {
                cout << "Wrong position!" << endl;
            }
        }

        switch (moveStatus.getType()) {

            case NONE:
                break;
            case NORMAL: {
                PieceModel *piece = board->getTile(oldY, oldX).getPiece();
                piece->setY(newY);
                piece->setX(newX);
                cout << piece->getX() << endl;
                if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                    int color = piece->getColor();
                    board->getTile(newY, newX).setPiece(new QueenModel(newY, newX, Color(color)));
                } else
                    board->getTile(newY, newX).setPiece(piece);
                cout << oldX << " " << oldY;
                board->getTile(oldY, oldX).setPiece(nullptr);
                break;
            }

            case KILL:
                PieceModel *piece = board->getTile(oldY, oldX).getPiece();
                piece->setY(newY);
                piece->setX(newX);
                if ((piece->getColor() == 1 && newY == 7) || (piece->getColor() == -1 && newY == 0)) {
                    int color = piece->getColor();
                    board->getTile(newY, newX).setPiece(new QueenModel(newY, newX, Color(color)));
                } else
                    board->getTile(newY, newX).setPiece(piece);
                board->getTile(oldY, oldX).setPiece(nullptr);

                PieceModel *otherPiece = moveStatus.getPiece();
                board->getTile(otherPiece->getY(), otherPiece->getX()).setPiece(nullptr);

                if (piece->getColor() == 1)
                    board->decrementWhiteCounter();
                else
                    board->decrementBlackCounter();

                break;
        }
    }
};

MoveStatus CheckerModel::move(vector<vector<TileModel>> tiles, int newY, int newX) {
    if (tiles[newY][newX].hasPiece() || (newY + newX) % 2 == 0) {
        return {NONE};
    }
    int y0 = this->getY();
    int x0 = this->getX();
    if (newY - y0 == (int) (this->getColor()) && abs(newX - x0) == 1) {
        return {NORMAL};
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

MoveStatus QueenModel::move(vector<vector<TileModel>> tiles, int newY, int newX) {
    if (tiles[newY][newX].hasPiece() || (newX + newY) % 2 == 0) {
        return {NONE};
    }

    int qy = this->getY();
    int qx = this->getX();
    bool isPieceOnWay = false;

    if (abs(newY - qy) == abs(newX - qx)) {
        PieceModel *piece = checkDiagonal(tiles, qy, qx, newY, newX);
        if (piece != nullptr && piece->getColor() != tiles[qy][qx].getPiece()->getColor()) {
            isPieceOnWay = true;
        }
        if (isPieceOnWay) {
            return {KILL, piece};
        }

        return {NORMAL};
    } else return {NONE};
}

PieceModel *QueenModel::checkDiagonal(const vector<vector<TileModel>> &tiles, int oldY, int oldX, int newY, int newX) {
    if (newX - oldX > 0 && newY - oldY < 0) {
        for (int y = oldY - 1, x = oldX + 1; y > newY && x < newX; x++, y--) {
            if (tiles[y][x].hasPiece()) {
                return tiles[y][x].getPiece();
            }
        }
    }
    if (newX - oldX < 0 && newY - oldY > 0) {
        for (int y = oldY + 1, x = oldX - 1; y < newY && x > newX; x--, y++) {
            if (tiles[y][x].hasPiece()) {
                return tiles[y][x].getPiece();
            }
        }
    }
    if (newX - oldX < 0 && newY - oldY < 0) {
        for (int y = oldY - 1, x = oldX - 1; y > newY && x > newX; x--, y--) {
            if (tiles[y][x].hasPiece()) {
                return tiles[y][x].getPiece();
            }
        }
    }
    if (newX - oldX > 0 && newY - oldY > 0) {
        for (int y = oldY + 1, x = oldX + 1; y < newY && x < newX; x++, y++) {
            if (tiles[y][x].hasPiece()) {
                return tiles[y][x].getPiece();
            }
        }
    }
    return nullptr;
}

int main() {

    auto *boardModel = new BoardModel();

    while (!boardModel->checkWinCondition()) {
        cout << "Score for white: " << 12 - boardModel->getBlackCounter() << endl;
        cout << "Score for black: " << 12 - boardModel->getWhiteCounter() << endl << endl;

        BoardView::printBoard(boardModel);
        int oldY, newY;
        char oldX, newX;

        cout << endl;
        if (boardModel->getPlayerTurn() == -1) { cout << endl << "Turn: WHITE" << endl; }
        else { cout << endl << "Turn: BLACK" << endl; }

        cout << "Pick your piece (number, letter): " << endl;
        cin >> oldY;
        cin >> oldX;

        cout << "Pick your move (number, letter): " << endl;
        cin >> newY;
        cin >> newX;

        BoardController::tryMove(oldY, oldX, newY, newX, boardModel);
    }
    return 0;
}
