#include "snakeGame.h"
#include "screen.h"
#include <stdlib.h>
#include <conio.h>

#define SNAKE_SIZE 256
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void FruitRandomPos(Position* pos)
{
    pos->x = rand() % screenWidth + 1;
    pos->y = rand() % screenHeight + 1;
}

void startSnakeGame() {
    Snake snake;
    Fruit fruit;    
    Position initialBody[SNAKE_SIZE] = { {20, 10}, {21, 10}, {22, 10} }; /* 뱀의 초기값 {머리}{꼬리1}{꼬리2} ... */
    snake.body = initialBody;
    snake.length = 3;
    snake.direction = LEFT;

    fruit.pos.x = 25;
    fruit.pos.y = 10;
    fruit.isActive = 1;

    int score = 0;
    while (1) 
    {
        /* 사용자 입력검사 */
        if (_kbhit()) {
            char ch = tolower(_getch()); /* 대문자로 입력해도 잘 입력되게 */
            /* 반대로 이동을 못하게 EX) 왼쪽이동시 오른쪽으로 바로 방향전환 X */
            if ((ch == UP && snake.direction != DOWN) || 
                (ch == DOWN && snake.direction != UP) ||
                (ch == LEFT && snake.direction != RIGHT) ||
                (ch == RIGHT && snake.direction != LEFT)) {
                snake.direction = ch;
            }
        }

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
            score += 50;
            FruitRandomPos(&(fruit.pos));
            fruit.isActive = 1;
        }

        /* 자신의 몸에 닿거나 벽에 닿을시 */
        for (int i = 1; i < snake.length; ++i) 
        {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) 
            {
                /* Game over */
                return 0;
            }
        }
        if (snake.body[0].x <= 0 || snake.body[0].x >= screenWidth  + 1||
            snake.body[0].y <= 0 || snake.body[0].y >= screenHeight + 1)
        {
            /* Game over */
            return 0;
        }

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

        if (fruit.isActive) 
        {
            WriteToBuffer(fruit.pos.x, fruit.pos.y, "#");
        }
        printf("Score: %d\n", score);
        DrawBuffer();

        /* 200 ms 딜레이 */
        Sleep(150);
    }
}


