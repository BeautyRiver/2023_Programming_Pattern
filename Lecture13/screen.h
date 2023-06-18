#pragma once
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//Ű�ڵ�
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_LEFT 75
#define KEY_RIGHT 77


//�� ũ��
#define MAP_WIDTH 70
#define MAP_HEIGHT 20

//�޽���
/* Ÿ��Ʋ */
#define TITLE_MSG "SNAKE GAME"
#define TITLE_MSG1 "       _____ _   _____    __ __ ______   _________    __  _________"
#define TITLE_MSG2 "     / ___// | / /   |  / //_// ____/  / ____/   |  /  |/  / ____/"
#define TITLE_MSG3 "  \\__ \\/  |/ / /| | / ,<  / __/    / / __/ /| | / /|_/ / __/"
#define TITLE_MSG4 " ___/ / /|  / ___ |/ /| |/ /___   / /_/ / ___ |/ /  / / /___"
#define TITLE_MSG5 "/____/_/ |_/_/  |_/_/ |_/_____/   \\____/_/  |_/_/  /_/_____/"

#define TITLE_MENU1 "���� ����"
#define TITLE_MENU2 "���� ����"
#define TITLE_MENU3 "���� ��ŷ"
#define TITLE_MENU4 "���� ����"

/* ���Ӽ��� */
#define INTRO_START "|���� ����|"
#define INTRO_MSG1 "SNAKE GAME�� ���� �����Ͽ� ����(#)�� �԰�"
#define INTRO_MSG2 "���� ���� ������� ����� �����Դϴ�."
#define INTRO_MSG3 "���� �ε����� LIFE�� �����մϴ�."
#define INTRO_MSG4 "������ �ڽ��� ���� �ε����� ���� ����ϰ� �˴ϴ�."
#define INTRO_MSG5 "LIFE�� 0�� �ɽ� GAME OVER�� �˴ϴ�."
#define INTRO_MSG6 "���� ���̸� �÷� ������ ����ϰ� �����ϼ���!!"

#define INTRO_KEY_START "|���� ���|"
#define INTRO_KEY_MSG1 "ESC(�ΰ��ӳ�) - �Ͻ�����"
#define INTRO_KEY_MSG2 "Ű���� ����Ű(��,��,��,��)"
#define INTRO_KEY_MSG3 "�����¿� �̵�"

/* �ΰ��� */
#define GAMEOVER_MSG "GAME OVER"
#define GAMEOVER_MSG1 "GAME OVER"
#define ENTER_NAME "Please enter your name: "
#define LIFE_MSG "LIFE: "
#define SELECT_CONTINUE "����ϱ�"
#define SELECT_RESTART "�ٽ��ϱ�"
#define SELECT_EXIT "�׸��ϱ�"

char *ScreenBuffer;

int screenWidth;
int screenHeight;

void setScreenSize(int width, int height);
void setCursorPos(int x, int y);
void SetCursorState(int visible);
void SetColor(unsigned short backGroundColor, unsigned short textColor);

void ClearBuffer();
void WriteToBuffer(int x, int y, const char* str);
void DrawBuffer();