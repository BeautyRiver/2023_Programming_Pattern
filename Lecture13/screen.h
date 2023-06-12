#pragma once
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

char *ScreenBuffer;

int screenWidth;
int screenHeight;

void setScreenSize(int width, int height);
void setCursorPos(int x, int y);
void SetCursorState(int visible);
void SetColor(unsigned short backGroundColor, unsigned short textColor);

void ClearBuffer();
int WriteToBuffer(int x, int y, const char* str);

