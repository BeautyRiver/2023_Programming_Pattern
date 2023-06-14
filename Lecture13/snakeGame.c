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
/* �����, �׾����� �˻�, Pauseâ�� ���ִ��� �˻�, �׸��ϱ⸦ �������� �˻� */

int life = 2;
int isDie = 1;
int isPauseOn = 0;
int score = 0;

int startSnakeGame()
{
	Snake snake;
	Fruit fruit;
	Position initialBody[SNAKE_SIZE] = { {20, 10}, {21, 10}, {22, 10} }; /* ���� �ʱ���ġ {�Ӹ�}{����1}{����2} ... */
	snake.length = 3;
	snake.body = initialBody;
	snake.direction = LEFT;

	FruitRandomPos(&fruit.pos); //��� ������ġ
	fruit.isActive = 1;

	//Frame����   
	unsigned long time_start, time_end, DeltaTime;
	time_end = GetTickCount();
	int sleepDelay = 150;
	int fruitScore = 50;
	while (1)
	{
		//�� ������ ������ ���� (���̵� ����)
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

		/* ü�� �˷��ֱ� ���ؼ� sprintf�� ���ڿ��� ��ȯ */
		char lifeStr[10];
		sprintf(lifeStr, "%d", life);

		/* ����� �Է°˻� Sleep�� ���� Ű������ �����ϱ� ���� �񵿱� GetAsync��� */
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

		//ESCAPEâ ����
		while (isPauseOn)
		{
			ClearBuffer();
			/* 1.����ϱ�, 2.���θ޴� */
			WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) - 30) / 2, 17, SELECT_CONTINUE);
			WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) + 30) / 2, 17, SELECT_EXIT);
			DrawBuffer();
			if (_kbhit)
			{
				char choiceFromEscape = _getch();
				if (choiceFromEscape == '1')
					isPauseOn = 0;
				else if (choiceFromEscape == '2')
					goto exit; //goto ��
			}
		}

		time_start = time_end;
		time_end = GetTickCount();
		DeltaTime = time_end - time_start;
		/* �� ��ġ ������Ʈ */
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

		/* ���� ������ �Ծ����� Ȯ�� */
		if (snake.body[0].x == fruit.pos.x && snake.body[0].y == fruit.pos.y)
		{
			fruit.isActive = 0;
			snake.length++;
			score += fruitScore;
			FruitRandomPos(&(fruit.pos));
			fruit.isActive = 1;
		}

		/* �ڽ��� ���� ��ų� ���� ������ */
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

		/* ȭ�鿡 �׸��� Draw*/
		ClearBuffer();
		//LIFE�� ȭ�鿡 �����
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

		//�� �׸���
		for (int i = 0; i < snake.length; ++i)
		{
			WriteToBuffer(snake.body[i].x, snake.body[i].y, "@");
		}

		//��� �׸���
		if (fruit.isActive)
		{
			WriteToBuffer(fruit.pos.x, fruit.pos.y, "#");
		}

		//score, fps �׸���
		printf("Score: %d\n", score);

		if (DeltaTime != 0)
		{
			printf("Frame time: %d ms, Frame rate: %d fps\n", DeltaTime, 1000 / DeltaTime);
		}

		//LIFE�� 0�϶�
		if (life == 0)
		{
			ClearBuffer();
			WriteToBuffer((MAP_WIDTH - strlen(GAMEOVER_MSG)) / 2, MAP_HEIGHT / 2, GAMEOVER_MSG);
			DrawBuffer();
			Sleep(2000);

			ClearBuffer();
			DrawBuffer();

			//��ŷ ���
			setCursorPos(23, 10);
			printf("Enter Your Name : ");
			char name[10];
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = '\0';			

			/* 1.�ٽ��ϱ�, 2.���θ޴� */
			WriteToBuffer((MAP_WIDTH - strlen("1. ���θ޴���")) / 2, 18, "1. ���θ޴���");
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


			//"2. �׸��ϱ�"�� ������ OR ���������			
		exit:
			life = 2;
			isPauseOn = 0;
			ClearBuffer();
			return 0;

		}
		DrawBuffer();
	}
}

//���� ���� ��ġ �Լ�
void FruitRandomPos(Position* pos)
{
	pos->x = rand() % screenWidth + 1;
	pos->y = rand() % screenHeight + 1;
}