#pragma once
#include <stdlib.h>
#include <conio.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position* body; /* 뱀의 길이가 계쏙 증가하기 때문에 동적할당을 위한 포인터 선언 */
    int length;
    char direction;
} Snake;

typedef struct {
    Position pos;
    int isActive;
} Fruit;

void FruitRandomPos(Position* pos);
int startSnakeGame();