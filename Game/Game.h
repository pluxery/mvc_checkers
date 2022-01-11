#pragma once

#include<Windows.h>
#include <string>
#include <conio.h>
#include "../Model/BoardModel.h"
#include "../View/BoardView.h"
#include "../View/BoardView.cpp"



struct Position {
    int oldY;
    int newY;
    char oldX;
    char newX;
};

void Launch();

bool KEY[256];

void GetKeyPressed();

void Render(BoardModel *boardModel);

Position Input(Position &pos);

void Update(Position pos, BoardModel *boardModel);




