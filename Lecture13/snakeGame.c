#define _CRT_SECURE_NO_WARNINGS
#include "snakeGame.h"
#include "screen.h"
#include "ranking.h"

#define SNAKE_SIZE 256
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void FruitRandomPos(Position* pos);
/* 생명력, 죽었는지 검사, Pause창이 떠있는지 검사, 그만하기를 눌렀는지 검사 */

int life = 2;
int isDie = 1;
int isPauseOn = 0;
int score = 0;

int startSnakeGame()
{
	Snake snake;
	Fruit fruit;
	Position initialBody[SNAKE_SIZE] = { {20, 10}, {21, 10}, {22, 10} }; /* 뱀의 초기위치 {머리}{꼬리1}{꼬리2} ... */
	snake.length = 3;
	snake.body = initialBody;
	snake.direction = LEFT;

	FruitRandomPos(&fruit.pos); //사과 랜덤배치
	fruit.isActive = 1;

	//Frame관련   
	unsigned long time_start, time_end, DeltaTime;
	time_end = GetTickCount();
	int sleepDelay = 150;
	int fruitScore = 50;
	while (1)
	{
		//뱀 움직임 딜레이 조절 (난이도 조절)
		Sleep(sleepDelay);
		if (score >= 300) 
		{
			sleepDelay = 130;
		}
		if (score >= 600)
		{
			sleepDelay = 110;
			fruitScore = 100;
		}
		if (score >= 1700)
		{
			sleepDelay = 80;
			fruitScore = 200;
		}
		if (score >= 3000)
		{
			sleepDelay = 60;
			fruitScore = 300;
		}

		/* 체력 알려주기 위해서 sprintf로 문자열로 변환 */
		char lifeStr[10];
		sprintf(lifeStr, "%d", life);

		/* 사용자 입력검사 Sleep에 의한 키씹힘을 방지하기 위한 비동기 GetAsync사용 */
		if ((GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) && snake.direction != DOWN)
			snake.direction = UP;

		else if ((GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) && snake.direction != UP)
			snake.direction = DOWN;

		else if ((GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) && snake.direction != RIGHT)
			snake.direction = LEFT;

		else if ((GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) && snake.direction != LEFT)
			snake.direction = RIGHT;

		else if (GetAsyncKeyState(VK_ESCAPE))
			isPauseOn = 1;

		//ESCAPE창 띄우기
		while (isPauseOn)
		{
			ClearBuffer();
			/* 1.계속하기, 2.메인메뉴 */
			WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) - 30) / 2, 17, SELECT_CONTINUE);
			WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) + 30) / 2, 17, SELECT_EXIT);
			DrawBuffer();
			if (_kbhit)
			{
				char choiceFromEscape = _getch();
				if (choiceFromEscape == '1')
					isPauseOn = 0;
				else if (choiceFromEscape == '2')
					goto exit; //goto 문
			}
		}

		time_start = time_end;
		time_end = GetTickCount();
		DeltaTime = time_end - time_start;
		/* 뱀 위치 업데이트 */
		for (int i = snake.length - 1; i > 0; --i)
		{
			snake.body[i] = snake.body[i - 1];
		}
		if (snake.direction == UP)
		{
			snake.body[0].y--;
		}
		else if (snake.direction == DOWN)
		{
			snake.body[0].y++;
		}
		else if (snake.direction == LEFT)
		{
			snake.body[0].x--;
		}
		else if (snake.direction == RIGHT)
		{
			snake.body[0].x++;
		}		

		/* 뱀이 과일을 먹었는지 확인 */
		if (snake.body[0].x == fruit.pos.x && snake.body[0].y == fruit.pos.y)
		{
			fruit.isActive = 0;
			snake.length++;
			score += fruitScore;
			FruitRandomPos(&(fruit.pos));
			fruit.isActive = 1;
		}

		/* 자신의 몸에 닿거나 벽에 닿을시 */
		for (int i = 1; i < snake.length; ++i)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				/* life - 1*/
				life--;
				isDie = 1;
				return 1;
			}
		}
		if (snake.body[0].x <= 0 || snake.body[0].x >= screenWidth + 1 ||
			snake.body[0].y <= 0 || snake.body[0].y >= screenHeight + 1)
		{
			/* life - 1 */
			life--;
			isDie = 1;
			return 1;
		}

		/* 화면에 그리기 Draw*/
		ClearBuffer();
		//LIFE를 화면에 띄워줌
		while (isDie)
		{
			ClearBuffer();
			WriteToBuffer((MAP_WIDTH - strlen(LIFE_MSG)) / 2, MAP_HEIGHT / 2, LIFE_MSG);
			WriteToBuffer((MAP_WIDTH) / 2 + 2, MAP_HEIGHT / 2, lifeStr);
			DrawBuffer();
			Sleep(1000);
			isDie = 0;
			ClearBuffer();
		}

		//뱀 그리기
		for (int i = 0; i < snake.length; ++i)
		{
			WriteToBuffer(snake.body[i].x, snake.body[i].y, "@");
		}

		//사과 그리기
		if (fruit.isActive)
		{
			WriteToBuffer(fruit.pos.x, fruit.pos.y, "#");
		}

		//score, fps 그리기
		printf("Score: %d\n", score);

		if (DeltaTime != 0)
		{
			printf("Frame time: %d ms, Frame rate: %d fps\n", DeltaTime, 1000 / DeltaTime);
		}

		//LIFE가 0일때
		if (life == 0)
		{
			ClearBuffer();
			WriteToBuffer((MAP_WIDTH - strlen(GAMEOVER_MSG)) / 2, MAP_HEIGHT / 2, GAMEOVER_MSG);
			DrawBuffer();
			Sleep(2000);

			ClearBuffer();
			DrawBuffer();

			//랭킹 기록
			setCursorPos(23, 10);
			printf("Enter Your Name : ");
			char name[10];
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = '\0';			

			/* 1.다시하기, 2.메인메뉴 */
			WriteToBuffer((MAP_WIDTH - strlen("1. 메인메뉴로")) / 2, 18, "1. 메인메뉴로");
			DrawBuffer();
			Score newScore;
			strcpy(newScore.name, name);
			newScore.score = score;
			recordScore("ranking.txt", newScore);						
			loadAndSortScores("ranking.txt");
			
			char escape;
			escape = _getch();
			if (escape == '1')
			{
				return 0;
			}


			//"2. 그만하기"를 누를때 OR 사망했을때			
		exit:
			life = 2;
			isPauseOn = 0;
			ClearBuffer();
			return 0;

		}
		DrawBuffer();
	}
}

//과일 랜덤 배치 함수
void FruitRandomPos(Position* pos)
{
	pos->x = rand() % screenWidth + 1;
	pos->y = rand() % screenHeight + 1;
}