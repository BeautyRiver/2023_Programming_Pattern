#define _CRT_SECURE_NO_WARNINGS
#include "screen.h"
#include "util.h"
#include "snakeGame.h"
#define MAP_WIDTH 70
#define MAP_HEIGHT 25
int Initialize();
int Release();
int DrawBuffer();

int main()
{
	int isGameRunning = 1;
	int isSnakeGameStarting = 0;
	int isGameIntroduce = 0;
	/* 체력 알려주기 위해서 sprintf로 문자열로 변환 WriteToBuffer매개변수가 문자열을 받아서... */
	int life = 1;
	char lifeStr[10];
	sprintf(lifeStr, "%d", life);
	CHECKERROR(Initialize());

	while (isGameRunning)
	{	
		SetCursorState(0); //커서비활성화
		SetColor(0b1000, 0b1111);

		WriteToBuffer(30, 7, "지렁이 게임");
		WriteToBuffer(30, 12, "1. 게임시작");
		WriteToBuffer(30, 13, "2. 게임설명");
		WriteToBuffer(30, 14, "3. 게임종료");
		
		DrawBuffer();
		
		if (_kbhit()) // 키가 눌렸는지 확인
		{
			char ch = _getch(); 
			if (ch == '1') // '1' 입력시 게임시작			
				isSnakeGameStarting = 1;
			
			else if (ch == '2') // '2' 입력시 종료			
				isGameIntroduce = 1; // 게임 종료				
			
			else if (ch == '3')			
				isGameRunning = 0;			
		}		

		while (isSnakeGameStarting) {
			ClearBuffer();
			/* 여기서부터 다시 짜야돼요~ 
			WriteToBuffer((MAP_WIDTH - 7) / 2, MAP_HEIGHT / 2, "LIFE: ");
			WriteToBuffer((MAP_WIDTH) / 2 + 2, MAP_HEIGHT / 2, lifeStr);*/
			DrawBuffer();
			startSnakeGame();
		}
						
		while (isGameIntroduce) {
			ClearBuffer();
			WriteToBuffer((MAP_WIDTH-11) / 2, MAP_HEIGHT / 2, "지렁이 게임");
			WriteToBuffer(30, 7, "등장하는 #(과일)을 먹고");
			DrawBuffer();
		}

		
	}

	CHECKERROR(Release());

	exit(0);
	return 0;
}

int Initialize()
{
	setScreenSize(MAP_WIDTH, MAP_HEIGHT);

	ClearBuffer();

	return 0;
}

//메모리 해제
int Release()
{
	if (ScreenBuffer != NULL) 
	{
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

