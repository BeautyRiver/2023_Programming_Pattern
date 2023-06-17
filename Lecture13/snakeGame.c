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

int life = 3; //생명력
int isDie = 1; //죽었는지 검사
int isPauseOn = 0; //Pause창이 열린 상태인지 검사
int score = 0; //점수
int snakeLengthSave = 3; //Snake의 길이 저장변수 (life가 감소해도 길이는 그대로 재시작)

int startSnakeGame()
{
	Snake snake;
	Fruit fruit;
	Position initialBody[SNAKE_SIZE] = { {20, 10}, {21, 10}, {22, 10}, {20, 10}, {21, 10}, {22, 10}, {23, 10}, {24, 10}, {25, 10} }; /* 뱀의 초기위치 {머리}{꼬리1}{꼬리2} ... */
	snake.length = snakeLengthSave;
	snake.body = initialBody;
	snake.direction = LEFT;
	
	FruitRandomPos(&fruit.pos); //과일 랜덤배치
	fruit.isActive = 1;

	//Frame관련   
	unsigned long time_start, time_end, DeltaTime;
	time_end = GetTickCount();
	int sleepDelay = 140;
	int fruitScore = 50;
	while (1)
	{
		//뱀 움직임 딜레이 조절 및 점수조정 (난이도 조절)
		Sleep(sleepDelay);
		if (score >= 300)
		{
			sleepDelay = 120;
		}
		if (score >= 600)
		{
			sleepDelay = 100;
			fruitScore = 100;
		}
		if (score >= 1700)
		{
			sleepDelay = 85;
			fruitScore = 200;
		}
		if (score >= 3000)
		{
			sleepDelay = 70;
			fruitScore = 300;
		}

		/* 체력 알려주기 위해서 sprintf로 문자열로 변환 */
		char lifeStr[10];
		sprintf(lifeStr, "%d", life);

		/* 사용자 입력검사 Sleep에 의한 키씹힘을 방지하기 위한 비동기 GetAsync사용 */
		if (GetAsyncKeyState(VK_UP) && snake.direction != DOWN)
			snake.direction = UP;

		else if (GetAsyncKeyState(VK_DOWN) && snake.direction != UP)
			snake.direction = DOWN;

		else if (GetAsyncKeyState(VK_LEFT) && snake.direction != RIGHT)
			snake.direction = LEFT;

		else if (GetAsyncKeyState(VK_RIGHT) && snake.direction != LEFT)
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
			Position newTailPos = snake.body[snake.length - 1]; // 꼬리 위치 저장
			snakeLengthSave++;
			snake.length = snakeLengthSave;
			snake.body[snake.length - 1] = newTailPos; // 꼬리 부분을 새로 생긴 부분의 위치로 설정
			score += fruitScore;
			FruitRandomPos(&(fruit.pos));
			fruit.isActive = 1;
		}

		/* 자신의 몸에 닿거나 벽에 닿을시 */
		for (int i = 1; i < snake.length; ++i)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				ClearBuffer();
				float j = 0;
				/* 자신의 몸에 닿으면 즉사*/
				while (j <= 1900) //sleep대신 while문으로 딜레이
				{
					WriteToBuffer((MAP_WIDTH - strlen("뱀이 몸을 뚫어 즉사했습니다...")) / 2, MAP_HEIGHT / 2, "뱀이 몸을 뚫어 즉사했습니다...");					
					DrawBuffer();
					j += 0.1;
				}
				life = 0;						
			}
		}

		if (snake.body[0].x <= 0 || snake.body[0].x >= screenWidth + 1 ||
			snake.body[0].y <= 0 || snake.body[0].y >= screenHeight + 1)
		{
			/* life - 1 */
			life-= 1;
			isDie = 1;
			snake.body = initialBody;
			snake.direction = LEFT;
			break;
		}

		/* 화면에 그리기 Draw*/
		ClearBuffer();
		//LIFE를 화면에 띄워줌
		while (isDie)
		{
			float i = 0;
			
			ClearBuffer();
			while (i <= 1900) //sleep대신 while문으로 딜레이
			{
				WriteToBuffer((MAP_WIDTH - strlen(LIFE_MSG)) / 2, MAP_HEIGHT / 2, LIFE_MSG);
				WriteToBuffer((MAP_WIDTH) / 2 + 2, MAP_HEIGHT / 2, lifeStr);
				DrawBuffer();
				i += 0.1;
			}

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
			float i = 0;

			ClearBuffer();
			while (i <= 3000) //sleep대신 while문으로 딜레이
			{				
				WriteToBuffer((MAP_WIDTH - strlen(GAMEOVER_MSG)) / 2, MAP_HEIGHT / 2, GAMEOVER_MSG);
				DrawBuffer();
				i += 0.1;
			}
			ClearBuffer();
			DrawBuffer();

			//랭킹 기록
			setCursorPos(23, 10);
			printf("Enter Your Name : ");
			char name[15];
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = '\0';

			/* 1.다시하기, 2.메인메뉴 */
			WriteToBuffer((MAP_WIDTH - strlen("아무키를 입력해주세요...")) / 2, 18, "아무키를 입력해주세요...");
			DrawBuffer();
			Score newScore;
			strcpy(newScore.name, name);
			newScore.score = score;
			recordScore("ranking.txt", newScore);
			loadAndSortScores("ranking.txt");

			char escape;
			escape = _getch();
		exit:
			isPauseOn = 0; //pause창 끄기	
			snakeLengthSave = 3; //길이다시 3으로 초기화			
			life = 3; //life 초기화
			isDie = 1; //LIFE 화면에 띄워주는 bool값 다시 참으로
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