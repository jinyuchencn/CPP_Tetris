#include <iostream>
#include <vector>
#include "render/platform.h"
#include "render/render.h"

bool g_window_should_close = false;



static const int WIDTH = 300;
static const int HEIGHT = 600;

const int size = 15;
const int LineSize = 1;

static std::vector<byte> RED = {255,0,0,255};

int main(int argc, char** argv) {


    Render render(WIDTH,HEIGHT);
    render.init();

    int left = 20;
    int tall = 20;

    while (!windowShouldClose()) {
        for(int i =0;i<10;i++){
            for(int j=0;j<15;j++){
                int x = (size + LineSize) *i + left;
                int y = (size + LineSize) *j + tall;
                render.drawRectangle(x, y, size, size, RED);
            }
        }


        render.update();

    }

    render.destroy();
    return 0;
}
