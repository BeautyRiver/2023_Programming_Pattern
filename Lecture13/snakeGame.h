#pragma once
#include <stdlib.h>
#include <conio.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position* body; /* ���� ���̰� ��� �����ϱ� ������ �����Ҵ��� ���� ������ ���� */
    int length;
    char direction;
} Snake;

typedef struct {
    Position pos;
    int isActive;
} Fruit;

int score;

void FruitRandomPos(Position* pos);
void startSnakeGame();