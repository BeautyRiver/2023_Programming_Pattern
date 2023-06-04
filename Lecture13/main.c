#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "screen.h"
#include "util.h"
#include "snakeGame.h"

int Initialize();
int Release();
int DrawBuffer();

int main()
{
	int isGameRunning = 1;
	int isGameStarting = 0;
	CHECKERROR(Initialize());

	unsigned long time_end = GetTickCount();
	unsigned long deltaTime = GetTickCount();

	while (isGameRunning)
	{
		SetColor(0b1000, 0b1111);

		WriteToBuffer(30, 7, "지렁이 게임");
		WriteToBuffer(30, 12, "1. 게임시작");
		WriteToBuffer(30, 13, "2. 게임종료");
		
		DrawBuffer();

		/*deltaTime = GetTickCount() - time_end;
		time_end = GetTickCount();
		if (deltaTime < 33)
			Sleep(33 - deltaTime);

		if (deltaTime != 0)
			printf("time : %d \nfps :%d\n", deltaTime, 1000 / deltaTime);*/

		if (_kbhit()) // 키가 눌렸는지 확인
		{
			char ch = _getch(); 
			if (ch == '1') // '1' 입력시 게임시작
			{
				isGameStarting = 1;
			}
			else if (ch == '2') // '2' 입력시 종료
			{
				isGameRunning = 0; // 게임 종료
			}
		}

		while (isGameStarting)
		{
			
			startSnakeGame();
		}
		

	}

	CHECKERROR(Release());

	exit(1);
	return 0;
}

int Initialize()
{
	setScreenSize(70, 20);

	ClearBuffer();

	return 0;
}

//메모리 해제
int Release()
{
	if (ScreenBuffer != NULL) {
		free(ScreenBuffer);
		ScreenBuffer = NULL;
	}
	return 0;
}

int DrawBuffer()
{
	setCursorPos(0, 0);
	printf("%s", ScreenBuffer);
	return 0;
}

