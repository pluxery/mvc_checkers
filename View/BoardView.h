#pragma once

#include<iostream>
#include "../Model/BoradModel.h"
#include "../Model/Figures/QueenModel.h"
//#include "View/Figures/CheckerView.h"
#include "View/Figures/QueenView.h"

//class CheckerView;
class QueenView;
using namespace std;

class BoardView {
public:
    static void printBoard(BoardModel *board);
};



