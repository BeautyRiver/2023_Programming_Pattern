#include "snakeGame.h"
#include "screen.h"


#define SNAKE_SIZE 256
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

//과일 랜덤 배치 함수
void FruitRandomPos(Position* pos)
{
	pos->x = rand() % screenWidth + 1;
	pos->y = rand() % screenHeight + 1;
}

void startSnakeGame(int *life)
{
	Snake snake;
	Fruit fruit;
	Position initialBody[SNAKE_SIZE] = { {20, 10}, {21, 10}, {22, 10} }; /* 뱀의 초기값 {머리}{꼬리1}{꼬리2} ... */
	snake.body = initialBody;
	snake.length = 3;
	snake.direction = LEFT;

	FruitRandomPos(&fruit.pos);
	fruit.isActive = 1;
	int score = 0;

	//Frame관련   
	unsigned long time_start, time_end, DeltaTime, DeltaTimeSum = 0;
	time_end = GetTickCount();

	while (life < 3)
	{
		/* 사용자 입력검사 Sleep에 의한 키씹힘을 방지하기 위한 비동기 GetAsync사용 */
		if ((GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) && snake.direction != DOWN) 
			snake.direction = UP;
		
		else if ((GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) && snake.direction != UP) 
			snake.direction = DOWN;
		
		else if ((GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) && snake.direction != RIGHT) 
			snake.direction = LEFT;
		
		else if ((GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) && snake.direction != LEFT) 
			snake.direction = RIGHT;
					
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
		DeltaTimeSum = 0;


		/* 뱀이 과일을 먹었는지 확인 */
		if (snake.body[0].x == fruit.pos.x && snake.body[0].y == fruit.pos.y)
		{
			fruit.isActive = 0;
			snake.length++;
			score += 50;
			FruitRandomPos(&(fruit.pos));
			fruit.isActive = 1;
		}

<<<<<<< HEAD
		/* 자신의 몸에 닿거나 벽에 닿을시 */
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
        /* 화면에 그리기 */
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

		/* 화면에 그리기 */
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

		/* 150 ms 딜레이 */
		Sleep(150);
	}
=======
        /* 200 ms 딜레이 */
        Sleep(150);
    }
>>>>>>> a54caef8e0f9a26af9eac2e4df1971e72ee8ec49
}


