#pragma once
#include <windows.h>
#include <assert.h>
#include <tchar.h>
#include <string>

#include "platform.h"



LRESULT CALLBACK process_message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


void registerClass();

void initializeWindow();

HWND createWindow(const std::string title,int WIDTH,int HEIGHT);

void createCanvas(HWND handle, int width, int height, byte** image, HDC *memoryDC);

LRESULT CALLBACK process_message(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

bool windowShouldClose();

