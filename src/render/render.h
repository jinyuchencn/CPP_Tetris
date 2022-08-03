#pragma once

#include <sys/stat.h>
#include <vector>
#include <map>

#include "Windows.h"

#include "common/vec.h"


enum class Color{
    Red=0,
    Green,
    Blue,
    White,
    Black
};

class Render{


public:


public:
    Render() = default;
    Render(int Width,int Height);

    void init();
    void update();

    void destroy();
    void drawLine(int x,int y,int length,int dir/*vertical if 0 */,std::vector<unsigned char> color);
    void drawRectangle(int x,int y,int w,int h,std::vector<unsigned char> color);
    void setPixel(int w, int h, const std::vector<unsigned char> & color,unsigned char* source);

    static std::vector<unsigned char> Red(){
        return m_colors[Color::Red];
    }
    static std::vector<unsigned char> Green(){
        return m_colors[Color::Green];
    }
    static std::vector<unsigned char> Blue(){
        return m_colors[Color::Blue];
    }
    static std::vector<unsigned char> White(){
        return m_colors[Color::White];
    }
    static std::vector<unsigned char> Black(){
        return m_colors[Color::Black];
    }


    
    ~Render();

private:

    static std::map<Color,std::vector<unsigned char>> m_colors;

    void platformInit();
    void platformUpdate();
    void platformDestroy();




    unsigned char* m_buffer;

    int m_width;
    int m_height;

    HDC m_memoryDC;
    HWND m_handle;
};