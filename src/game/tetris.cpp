#include "tetris.h"


void Board::down(){

}

void Board::update(){

    down();
    flashBoard();
}

void Tetris::update(double delta){
    m_time+=delta;
    if(m_time>1){
        m_board.update();
        m_time-=1;
    }
}