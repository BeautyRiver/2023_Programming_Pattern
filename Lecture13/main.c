#include "screen.h"
#include "util.h"
#include "snakeGame.h"

int Initialize();
int Release();

int main()
{	
	int isGameRunning = 1;
	int isSnakeGameStarting = 0;
	int isGameIntroduce = 0;
	
	CHECKERROR(Initialize());

	while (isGameRunning)
	{	
		/* TITLE SCREEN 설명 */
		SetCursorState(0); //커서비활성화
		SetColor(0b0000, 0b0010);

		/*SNAKE GAME BANNER*/
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG1)) / 2, 2, TITLE_MSG1);
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG2)) / 2, 3, TITLE_MSG2);
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG3)) / 2, 4, TITLE_MSG3);
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG4)) / 2, 5, TITLE_MSG4);
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG5)) / 2, 6, TITLE_MSG5);

		/*1.게임시작, 2.게임설명, 3.게임 종료*/
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU1)) / 2, 14, TITLE_MENU1);
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU2)) / 2, 15, TITLE_MENU2);
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU3)) / 2, 16, TITLE_MENU3);
				
		DrawBuffer();
		
		if (_kbhit()) // 키가 눌렸는지 확인
		{
			char ch = _getch(); 
			if (ch == '1') // '1' 입력시 게임시작			
				isSnakeGameStarting = 1;
			
			else if (ch == '2')	// '2' 입력시 설명
				isGameIntroduce = 1; 				
			
			else if (ch == '3')	 // '3' 입력시 종료				
				isGameRunning = 0; // 게임 종료	
		}		

		/* 게임START */
		while (isSnakeGameStarting) 
		{			
			startSnakeGame();					
		}
						
		/* 게임설명 창 */
		while (isGameIntroduce) {
			ClearBuffer();			
			/*SNAKE GAME BANNER*/
			WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG1)) / 2, 2, TITLE_MSG1);
			WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG2)) / 2, 3, TITLE_MSG2);
			WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG3)) / 2, 4, TITLE_MSG3);
			WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG4)) / 2, 5, TITLE_MSG4);
			WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG5)) / 2, 6, TITLE_MSG5);

			/*SNAKE GAME INTRODUCE*/
			WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG1)) / 2, 10, INTRO_MSG1);
			WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG2)) / 2, 11, INTRO_MSG2);
			WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG3)) / 2, 12, INTRO_MSG3);
			WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG4)) / 2, 13, INTRO_MSG4);
			WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG5)) / 2, 14, INTRO_MSG5);
			WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG6)) / 2, 15, INTRO_MSG6);
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



