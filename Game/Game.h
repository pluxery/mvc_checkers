#pragma once

#include<Windows.h>
#include <string>
#include <conio.h>
#include <thread>
#include <chrono>
#include "../Model/BoardModel.h"
#include "../View/BoardView.h"
#include "../View/BoardView.cpp"

struct Buffer {
    char oldY, oldX, newY, newX;

    void parseCoords();

};

void Launch();

bool KEY[256];

void GetKeyPressed();

void AsyncExitListener();

Buffer Input(Buffer &coords);

void Render(BoardModel *boardModel);

void Update(Buffer coords, BoardModel *boardModel);




