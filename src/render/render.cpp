#include "render.h"
#include "platform.h"
#include <vector>

static std::vector<byte> RED = {255,0,0,255};
static const char* const WINDOW_ENTRY_NAME = "Entry";

void Render::setPixel(int w, int h, const std::vector<unsigned char> & color,unsigned char* source)
{
    auto index = (m_width * h + w)*4;

	source[index] = color[2];                    // b
	source[index + 1] = color[1];				 // g
	source[index + 2] = color[0];				 // r
	source[index + 3] = color[3];				 // a	
}


Render::Render(int w,int h){
    m_width = w;
    m_height = h;
    m_buffer = new unsigned char[w * h * 4];
    
    m_colors[Color::Red] = std::vector<unsigned char>{255,0,0,255};
    m_colors[Color::Green] = std::vector<unsigned char>{0,255,0,255};
    m_colors[Color::Blue] = std::vector<unsigned char>{0,0,255,255};
    m_colors[Color::White] = std::vector<unsigned char>{255,255,255,255};
    m_colors[Color::Black] = std::vector<unsigned char>{0,0,0,255};

}

Render::~Render(){
    delete m_buffer;
    m_buffer = nullptr;
}   

void Render::platformInit()
{
    // auto p = m_image.data();
    // auto pp = &p;
	initializeWindow();	
    m_handle = createWindow("SoftwareRenderer", m_width, m_height);
    createCanvas(m_handle, m_width, m_height, &m_buffer, &m_memoryDC);
	SetProp(m_handle, WINDOW_ENTRY_NAME, m_handle);
	ShowWindow(m_handle, SW_SHOW);
}

void Render::platformUpdate()
{
    HDC window_dc = GetDC(m_handle);
	BitBlt(window_dc, 0, 0, m_width, m_height, m_memoryDC, 0, 0, SRCCOPY);        
    ReleaseDC(m_handle, window_dc);
	UpdateWindow(m_handle);
	MSG message;
	while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}


void Render::platformDestroy()
{
    RemoveProp(m_handle, WINDOW_ENTRY_NAME);
	DeleteDC(m_memoryDC);
	DestroyWindow(m_handle);
}

void Render::init()
{
    platformInit();
}

void Render::update()
{
    platformUpdate();
}

void Render::destroy()
{   
    platformDestroy();
}


void Render::drawLine(int x,int y,int length,int dir/*vertical if 0 */,std::vector<unsigned char> color)
{
    if(dir == 0){
        for(int i = x;i<length;i++){
            setPixel(i, y, color, m_buffer);
        }
    }
    else {
        for(int j = y;y<length;j++){
            setPixel(x, j, color, m_buffer);
        }
    }
}

void Render::drawRectangle(int x,int y,int w,int h,std::vector<unsigned char> color)
{
    for(int i=x;i<w+x;i++){
        for(int j=y;j<y+h;j++){
            setPixel(i, j, color, m_buffer);
        }
    }
}