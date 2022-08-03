#pragma once

#include <vector>
#include <map>

#include "Windows.h"

#include "common/vec.h"

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
        return std::vector<unsigned char>{255,0,0,255};
    }
    static std::vector<unsigned char> Green(){
        return std::vector<unsigned char>{0,255,0,255};
    }
    static std::vector<unsigned char> Blue(){
        return std::vector<unsigned char>{0,0,255,255};
    }
    static std::vector<unsigned char> White(){
        return std::vector<unsigned char>{255,255,255,255};
    }
    static std::vector<unsigned char> Black(){
        return std::vector<unsigned char>{0,0,0,255};
    }
    
    ~Render();

private:

    void platformInit();
    void platformUpdate();
    void platformDestroy();




    unsigned char* m_buffer;

    int m_width;
    int m_height;

    HDC m_memoryDC;
    HWND m_handle;
};