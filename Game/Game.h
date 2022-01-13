#pragma once

#include<Windows.h>
#include <string>
#include <conio.h>
#include <thread>
#include <chrono>
#include "../Model/BoardModel.h"
#include "../View/BoardView.h"
#include "../View/BoardView.cpp"

class Position {

public:
    char oldY, oldX, newY, newX;

    void ParseCoords();
};

void Launch();

bool KEY[256];

void GetKeyPressed();

void AsyncExitListener();

Position Input(Position &coords);

void Render(BoardModel *boardModel);

void Update(Position pos, BoardModel *boardModel);




