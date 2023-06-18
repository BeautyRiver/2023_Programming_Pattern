#pragma once
#include <conio.h>
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position* body;
    int length;
    char direction;
} Snake;

typedef struct {
    Position pos;
    int isActive;
} Fruit;

void FruitRandomPos(Position* pos);
int startSnakeGame();