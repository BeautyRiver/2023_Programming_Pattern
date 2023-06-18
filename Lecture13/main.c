#include "screen.h"
#include "snakeGame.h"


int Initialize();
int Release();
int WriteTitleScreenMsg();
int WriteIntroduceScreenMsg();

int main()
{
	int isGameRunning = 1; //프로그램이 실행중인지 체크하는 변수
	int isSnakeGameStarting = 0; //뱀게임이 실행체크 변수
	int isGameIntroduce = 0; //설명창 체크변수
	int isGameRanking = 0; //랭킹창 체크변수
	int selectHeight = 14; //화살표▶ 메뉴 SELECT 세로위치 변수
	Initialize();

	while (isGameRunning)
	{
		ClearBuffer();
		/* TITLE SCREEN 설명 */
		SetCursorState(0); //커서비활성화
		SetColor(0, 15); //흰색으로
		WriteTitleScreenMsg(); //TitleScreen메시지 버퍼입력

		/* 화살표▶ 메뉴 SELECT */
		WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU1) - 6) / 2, selectHeight, "▶");
		if (_kbhit()) // 키가 눌렸는지 확인
		{			
			ClearBuffer();

			int ch = _getch();
			if (ch == KEY_UP)
			{
				if (selectHeight > 14)	selectHeight -= 1;
				WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU1) - 6) / 2, selectHeight, "▶");
				DrawBuffer();
			}
			else if (ch == KEY_DOWN)
			{
				if (selectHeight < 17)	selectHeight += 1;
				WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU1) - 6) / 2, selectHeight, "▶");
				DrawBuffer();
			}
			if (ch == KEY_ENTER)
			{
				if (selectHeight == 14)	isSnakeGameStarting = 1;
				else if (selectHeight == 15) isGameIntroduce = 1;
				else if (selectHeight == 16) isGameRanking = 1;
				else if (selectHeight == 17) isGameRunning = 0;
			}
		}
		DrawBuffer(); //버퍼출력

		/* 게임START */
		while (isSnakeGameStarting)
		{
			SetColor(0, 2); //초록색으로
			ClearBuffer();
			if (startSnakeGame() == 0) //return 값이 0일때 : gameover 되거나 그만하기 눌렀을때 (정상종료)
			{
				isSnakeGameStarting = 0;
				ClearBuffer();
				system("cls");
			}
		}

		/* 게임설명 창 */
		while (isGameIntroduce)
		{
			WriteIntroduceScreenMsg(); //Introduce 메시지 출력
			char escape;
			escape = _getch();
			if (escape == KEY_ENTER) //메인화면으로
			{
				isGameIntroduce = 0;
			}
		}
		/* 게임 랭킹 창 */
		while (isGameRanking)
		{
			ClearBuffer();
			WriteToBuffer((MAP_WIDTH - strlen("Enter 메인메뉴로")) / 2, 18, "Enter 메인메뉴로");
			DrawBuffer();
			loadAndSortScores("ranking.txt");
			char escape;
			escape = _getch();
			if (escape == KEY_ENTER) //메인화면으로
			{
				isGameRanking = 0;
			}
		}
	}
	WriteToBuffer((MAP_WIDTH - strlen("게임을 종료합니다...")) / 2, MAP_HEIGHT / 2, "게임을 종료합니다...");
	DrawBuffer();
	Release();
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

int WriteTitleScreenMsg()
{
	/*SNAKE GAME BANNER*/
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG1)) / 2, 2, TITLE_MSG1);
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG2)) / 2, 3, TITLE_MSG2);
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG3)) / 2, 4, TITLE_MSG3);
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG4)) / 2, 5, TITLE_MSG4);
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MSG5)) / 2, 6, TITLE_MSG5);

	/*1.게임시작, 2.게임설명, 3.게임 랭킹, 4.게임 종료*/
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU1)) / 2, 14, TITLE_MENU1);
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU2)) / 2, 15, TITLE_MENU2);
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU3)) / 2, 16, TITLE_MENU3);
	WriteToBuffer((MAP_WIDTH - strlen(TITLE_MENU4)) / 2, 17, TITLE_MENU4);


	return 0;
}

int WriteIntroduceScreenMsg()
{
	ClearBuffer();
	/*SNAKE GAME INTRODUCE*/
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_START)) / 2, 2, INTRO_START);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG1)) / 2, 4, INTRO_MSG1);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG2)) / 2, 5, INTRO_MSG2);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG3)) / 2, 6, INTRO_MSG3);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG4)) / 2, 7, INTRO_MSG4);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG5)) / 2, 8, INTRO_MSG5);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_MSG6)) / 2, 9, INTRO_MSG6);

	WriteToBuffer((MAP_WIDTH - strlen(INTRO_KEY_START)) / 2, 11, INTRO_KEY_START);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_KEY_MSG1)) / 2, 13, INTRO_KEY_MSG1);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_KEY_MSG2)) / 2, 14, INTRO_KEY_MSG2);
	WriteToBuffer((MAP_WIDTH - strlen(INTRO_KEY_MSG3)) / 2, 15, INTRO_KEY_MSG3);


	/* 1.계속하기, 2.메인메뉴 */
	WriteToBuffer((MAP_WIDTH - strlen("Enter 메인메뉴로")) / 2, 18, "Enter 메인메뉴로");
	DrawBuffer();

	return 0;
}


