#pragma once

char *ScreenBuffer;	/* 화면이 차지하는 최대 메모리를 65,536 */

int screenWidth;
int screenHeight;

void setScreenSize(int width, int height);
void setCursorPos(int x, int y);
void SetColor(unsigned short backGroundColor, unsigned short textColor);

void ClearBuffer();
int WriteToBuffer(int x, int y, const char* str);

