#include "snakeGame.h"
#include "screen.h"


#define SNAKE_SIZE 256
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

//���� ���� ��ġ �Լ�
void FruitRandomPos(Position* pos)
{
	pos->x = rand() % screenWidth + 1;
	pos->y = rand() % screenHeight + 1;
}

void startSnakeGame(int *life)
{
	Snake snake;
	Fruit fruit;
	Position initialBody[SNAKE_SIZE] = { {20, 10}, {21, 10}, {22, 10} }; /* ���� �ʱⰪ {�Ӹ�}{����1}{����2} ... */
	snake.body = initialBody;
	snake.length = 3;
	snake.direction = LEFT;

	FruitRandomPos(&fruit.pos);
	fruit.isActive = 1;
	int score = 0;

	//Frame����   
	unsigned long time_start, time_end, DeltaTime, DeltaTimeSum = 0;
	time_end = GetTickCount();

	while (life < 3)
	{
		/* ����� �Է°˻� Sleep�� ���� Ű������ �����ϱ� ���� �񵿱� GetAsync��� */
		if ((GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) && snake.direction != DOWN) 
			snake.direction = UP;
		
		else if ((GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) && snake.direction != UP) 
			snake.direction = DOWN;
		
		else if ((GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) && snake.direction != RIGHT) 
			snake.direction = LEFT;
		
		else if ((GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) && snake.direction != LEFT) 
			snake.direction = RIGHT;
					
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
		DeltaTimeSum = 0;


		/* ���� ������ �Ծ����� Ȯ�� */
		if (snake.body[0].x == fruit.pos.x && snake.body[0].y == fruit.pos.y)
		{
			fruit.isActive = 0;
			snake.length++;
			score += 50;
			FruitRandomPos(&(fruit.pos));
			fruit.isActive = 1;
		}

<<<<<<< HEAD
		/* �ڽ��� ���� ��ų� ���� ������ */
		for (int i = 1; i < snake.length; ++i)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				/* Game over */
				*life--;
				return 0;
			}
		}
		if (snake.body[0].x <= 0 || snake.body[0].x >= screenWidth + 1 ||
			snake.body[0].y <= 0 || snake.body[0].y >= screenHeight + 1)
		{
			/* Game over */
			*life--;
			return 0;
		}
=======
        /* ȭ�鿡 �׸��� */
        ClearBuffer();
        for (int i = 0; i < snake.length; ++i) 
        {
            WriteToBuffer(snake.body[i].x, snake.body[i].y, "@");                        
            if (snake.body[i].x == snake.body[0].x && snake.body[i].y == snake.body[0].y)
            {
                WriteToBuffer(snake.body[i].x, snake.body[i].y, "O");
            }
        }
>>>>>>> a54caef8e0f9a26af9eac2e4df1971e72ee8ec49

		/* ȭ�鿡 �׸��� */
		ClearBuffer();
		for (int i = 0; i < snake.length; ++i)
		{
			WriteToBuffer(snake.body[i].x, snake.body[i].y, "@");
		}

<<<<<<< HEAD
		if (fruit.isActive)
		{
			WriteToBuffer(fruit.pos.x, fruit.pos.y, "#");
		}
		printf("Score: %d\n", score);

		time_start = time_end;
		time_end = GetTickCount();
		DeltaTime = time_end - time_start;

		if (DeltaTime != 0) {
			printf("Frame time: %d ms, Frame rate: %d fps\n", DeltaTime, 1000 / DeltaTime);
		}

		DrawBuffer();

		/* 150 ms ������ */
		Sleep(150);
	}
=======
        /* 200 ms ������ */
        Sleep(150);
    }
>>>>>>> a54caef8e0f9a26af9eac2e4df1971e72ee8ec49
}


