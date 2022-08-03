#pragma once
#include <vector>
#include "game/tetris.h"

class TetrisBlock{

};

class Tetris{
    void createBoard();
    void update();

private:
    std::vector<TetrisBlock> blocks;

    TetrisBlock activeBlock;
};