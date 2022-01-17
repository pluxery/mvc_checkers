#pragma once

#include<Windows.h>
#include <string>
#include <conio.h>
#include <thread>
#include <chrono>
#include "../Model/BoardModel/BoardModel.h"
#include "../View/BoardView/BoardView.h"
#include "../View/BoardView/BoardView.cpp"

struct Buffer {
    int oldY, newY;
    char  oldX, newX;
    void parseCoords();
};

void Launch();

bool KEY[256];

void GetKeyPressed();

void AsyncExitListener();

Buffer Input(Buffer &coords);

void Render(BoardModel *boardModel);

void Update(Buffer coords, BoardModel *boardModel);




