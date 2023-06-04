#pragma once

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

int score;

void FruitRandomPos(Position* pos);
void startSnakeGame();