#include "snakeGame.h"
#include "screen.h"
#include <stdlib.h>
#include <conio.h>

#define SNAKE_SIZE 256
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void startSnakeGame() {
    Snake snake;
    Fruit fruit;

    Position initialBody[SNAKE_SIZE] = { {10, 10}, {11, 10}, {12, 10} };
    snake.body = initialBody;
    snake.length = 3;
    snake.direction = LEFT;

    fruit.pos.x = 15;
    fruit.pos.y = 10;
    fruit.isActive = 1;

    while (1) {
        /* Check user input. */
        if (_kbhit()) {
            char ch = _getch();
            if (ch == UP || ch == DOWN || ch == LEFT || ch == RIGHT) {
                snake.direction = ch;
            }
        }

        /* Update snake position. */
        for (int i = snake.length - 1; i > 0; --i) {
            snake.body[i] = snake.body[i - 1];
        }
        if (snake.direction == UP) {
            snake.body[0].y--;
        }
        else if (snake.direction == DOWN) {
            snake.body[0].y++;
        }
        else if (snake.direction == LEFT) {
            snake.body[0].x--;
        }
        else if (snake.direction == RIGHT) {
            snake.body[0].x++;
        }

        /* Check if snake ate the fruit. */
        if (snake.body[0].x == fruit.pos.x && snake.body[0].y == fruit.pos.y) {
            fruit.isActive = 0;
            snake.length++;
        }

        /* Check if snake hit itself or the screen boundary. */
        for (int i = 1; i < snake.length; ++i) {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                /* Game over. */
                return;
            }
        }
        if (snake.body[0].x < 0 || snake.body[0].x >= screenWidth ||
            snake.body[0].y < 0 || snake.body[0].y >= screenHeight) {
            /* Game over. */
            return;
        }

        /* Draw everything on the screen. */
        ClearBuffer();
        for (int i = 0; i < snake.length; ++i) {
            WriteToBuffer(snake.body[i].x, snake.body[i].y, "*");
        }
        if (fruit.isActive) {
            WriteToBuffer(fruit.pos.x, fruit.pos.y, "#");
        }
        DrawBuffer();

        /* Delay for a while. */
        Sleep(200);
    }
}
