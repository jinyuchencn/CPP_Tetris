#pragma once
#include <vector>
#include "game/tetris.h"
#include "render/render.h"



class Block{

private:
    int state;
    Color color = Color::Black;

};

class Board{
public:
    void update();
    void down();
private:
    std::vector<std::vector<Block>> blocks;
};

class Tetris{
    void createBoard();
    void update(double delta);

private:
    double m_time  = 0.0;
    Board m_board;
};