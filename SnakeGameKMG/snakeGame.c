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
/* ������, �׾����� �˻�, Pauseâ�� ���ִ��� �˻�, �׸��ϱ⸦ �������� �˻� */

int life = 3; //������
int isDie = 1; //�׾����� �˻�
int isPauseOn = 0; //Pauseâ�� ���� �������� �˻�
int isPauseSelectisLeft = 2;
int score = 0; //����
int snakeLengthSave = 3; //Snake�� ���� ���庯�� (life�� �����ص� ���̴� �״�� �����)
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int startSnakeGame()
{
	Snake snake;
	Fruit fruit;
	Position initialBody[SNAKE_SIZE] = { {20, 10}, {21, 10}, {22, 10}, {20, 10}, {21, 10}, {22, 10}, {23, 10}, {24, 10}, {25, 10} }; /* ���� �ʱ���ġ {�Ӹ�}{����1}{����2} ... */
	snake.length = snakeLengthSave;
	snake.body = initialBody;
	snake.direction = LEFT;

	FruitRandomPos(&fruit.pos); //���� ������ġ
	fruit.isActive = 1;

	//Frame����   
	unsigned long time_start, time_end, DeltaTime;
	time_end = GetTickCount();
	int sleepDelay = 125;
	int fruitScore = 50;
	while (1)
	{
		//�� ������ ������ ���� �� �������� (���̵� ����)
		Sleep(sleepDelay);
		if (score >= 300)
		{
			sleepDelay = 110;
		}
		if (score >= 600)
		{
			sleepDelay = 95;
			fruitScore = 100;
		}
		if (score >= 1700)
		{
			sleepDelay = 85;
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
		if (GetAsyncKeyState(VK_UP) && snake.direction != DOWN)
			snake.direction = UP;

		else if (GetAsyncKeyState(VK_DOWN) && snake.direction != UP)
			snake.direction = DOWN;

		else if (GetAsyncKeyState(VK_LEFT) && snake.direction != RIGHT)
			snake.direction = LEFT;

		else if (GetAsyncKeyState(VK_RIGHT) && snake.direction != LEFT)
			snake.direction = RIGHT;

		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			isPauseOn = 1;
			ClearBuffer();
		}

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
			Position newTailPos = snake.body[snake.length - 1]; // ���� ��ġ ����
			snakeLengthSave++;
			snake.length = snakeLengthSave;
			snake.body[snake.length - 1] = newTailPos; // ���� �κ��� ���� ���� �κ��� ��ġ�� ����
			score += fruitScore;
			FruitRandomPos(&(fruit.pos));
			fruit.isActive = 1;
		}

		/* �ڽ��� ���� ��ų� ���� ������ */
		for (int i = 1; i < snake.length; ++i)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				ClearBuffer();
				/* �ڽ��� ���� ������ ���*/
				WriteToBuffer((MAP_WIDTH - strlen("���� ���� �վ� ����߽��ϴ�...")) / 2, MAP_HEIGHT / 2, "���� ���� �վ� ����߽��ϴ�...");
				DrawBuffer();
				Sleep(1500);
				life = 0;
			}
		}

		if (snake.body[0].x <= 0 || snake.body[0].x >= screenWidth + 1 ||
			snake.body[0].y <= 0 || snake.body[0].y >= screenHeight + 1)
		{
			/* life - 1 */
			life -= 1;
			isDie = 1;
			snake.body = initialBody;
			snake.direction = LEFT;
			break;
		}
		/*--------------------------------------------------------------------------------------------------------------------------------------------*/

		/* ȭ�鿡 �׸��� Draw*/
		//Pauseâ ����
		while (isPauseOn)
		{
			/* 1.����ϱ�, 2.���θ޴� */
			WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) - 30) / 2, 17, SELECT_CONTINUE);
			WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) + 30) / 2, 17, SELECT_EXIT);

			if (_kbhit()) // Ű�� ���ȴ��� Ȯ��
			{
				ClearBuffer();
				int ch = _getch();
				if (ch == KEY_LEFT)
				{
					WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) - 36) / 2, 17, "��");
					isPauseSelectisLeft = 1;
					DrawBuffer();
				}
				else if (ch == KEY_RIGHT)
				{
					WriteToBuffer((MAP_WIDTH - strlen(SELECT_CONTINUE) + 24) / 2, 17, "��");
					isPauseSelectisLeft = 0;
					DrawBuffer();
				}
				if (ch == KEY_ENTER)
				{
					if (isPauseSelectisLeft == 1) isPauseOn = 0;
					else if (isPauseSelectisLeft == 0) goto exit;
					ClearBuffer();
				}
			}
			DrawBuffer();
		}

		//LIFE�� ȭ�鿡 �����
		ClearBuffer();
		while (isDie)
		{
			ClearBuffer();
			WriteToBuffer((MAP_WIDTH - strlen(LIFE_MSG)) / 2, MAP_HEIGHT / 2, LIFE_MSG);
			WriteToBuffer((MAP_WIDTH) / 2 + 2, MAP_HEIGHT / 2, lifeStr);
			DrawBuffer();
			Sleep(1500);
			isDie = 0;
			ClearBuffer();
		}

		//�� �׸���
		for (int i = 0; i < snake.length; ++i)
		{			
			if (i == 0)
			{
				WriteToBuffer(snake.body[i].x, snake.body[i].y, "@");
			}
			else
				WriteToBuffer(snake.body[i].x, snake.body[i].y, "o");
		}

		//��� �׸���
		if (fruit.isActive)
		{
			WriteToBuffer(fruit.pos.x, fruit.pos.y, "#");
		}

		//score, fps �׸���
		printf("Score: %d\n", score);

		time_start = time_end;
		time_end = GetTickCount();
		DeltaTime = time_end - time_start;
		if (DeltaTime != 0)
		{
			printf("Frame time: %d ms, Frame rate: %2d fps \n", DeltaTime, 1000 / DeltaTime);
		}

		//LIFE�� 0�϶�
		if (life == 0)
		{
			float i = 0;
			ClearBuffer();

			WriteToBuffer((MAP_WIDTH - strlen(GAMEOVER_MSG)) / 2, MAP_HEIGHT / 2, GAMEOVER_MSG);
			DrawBuffer();
			Sleep(1500);
			ClearBuffer();
			SetColor(0, 15); //�������
			DrawBuffer();

			//��ŷ ���
			setCursorPos(23, 10);
			printf("Enter Your Name : ");
			char name[15];
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = '\0';

			/* anykey press.. */
			WriteToBuffer((MAP_WIDTH - strlen("�ƹ�Ű�� �Է����ּ���...")) / 2, 18, "�ƹ�Ű�� �Է����ּ���...");
			DrawBuffer();
			Score newScore;
			strcpy(newScore.name, name);
			newScore.score = score;
			recordScore("ranking.txt", newScore);
			loadAndSortScores("ranking.txt");

			char escape;
			escape = _getch();
		exit:
			isPauseOn = 0; //pauseâ ����	
			snakeLengthSave = 3; //���̴ٽ� 3���� �ʱ�ȭ			
			life = 3; //life �ʱ�ȭ
			score = 0; //Score �ʱ�ȭ
			isDie = 1; //LIFE ȭ�鿡 ����ִ� bool�� �ٽ� ������
			ClearBuffer();
			return 0;

		}
		DrawBuffer();
	}
}
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

//���� ���� ��ġ �Լ�
void FruitRandomPos(Position* pos)

{
	pos->x = rand() % screenWidth + 1;
	pos->y = rand() % screenHeight + 1;
}