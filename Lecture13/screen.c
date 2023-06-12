#include "screen.h"

void setScreenSize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;

	int bufferSize = (width + 3) * (height + 2);

	if (ScreenBuffer != NULL) 
	{
		free(ScreenBuffer);
		ScreenBuffer = NULL;
	}

	ScreenBuffer = (char*)malloc(sizeof(char) * bufferSize);

	if (ScreenBuffer == NULL) 
	{
		printf("메모리 할당 실패\n");
		exit(1);
	}
}
//커서이동
void setCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//커서비활성화
void SetCursorState(int visible)
{
	CONSOLE_CURSOR_INFO consoleCursorInfo;
	consoleCursorInfo.bVisible = visible;
	consoleCursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
}

// 0000(배경) 0000(글자)
void SetColor(unsigned short backGroundColor, unsigned short textColor)
{
	unsigned color;
	color = (backGroundColor << 4) + textColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//버퍼 초기화
void ClearBuffer()
{
	int y = 0;
	while (y < screenHeight + 2)
	{
		int x = 0;
		while (x < screenWidth + 2)
		{
			if (y == 0 || y == (screenHeight + 1))
				ScreenBuffer[x + (y * (screenWidth + 3))] = '-';
			else
			{
				if (x == 0 || x == (screenWidth + 1))
					ScreenBuffer[x + (y * (screenWidth + 3))] = '|';
				else
					ScreenBuffer[x + (y * (screenWidth + 3))] = ' ';
			}
			x += 1;
		}
		ScreenBuffer[x + (y * (screenWidth + 3))] = '\n';
		y += 1;
	}
	ScreenBuffer[(y * (screenWidth + 3))] = '\0';
}

int WriteToBuffer(int x, int y, const char* str)
{
	int i = 0;
	while (i < strlen(str))
	{
		ScreenBuffer[x + (y * (screenWidth + 3)) + i] = str[i];
		i = i + 1;
	}

	return 0;
}