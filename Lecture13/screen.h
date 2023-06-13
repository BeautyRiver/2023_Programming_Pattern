#pragma once
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

#define TITLE_MENU1 "1.���� ����"
#define TITLE_MENU2 "2.���� ����"
#define TITLE_MENU3 "3.���� ����"

/* ���Ӽ��� */
#define INTRO_START "|���� ����|"
#define INTRO_MSG1 "SNAKE GAME�� ���� �����Ͽ� ����(#)�� �԰�"
#define INTRO_MSG2 "���� ���� ������� ����� �����Դϴ�."
#define INTRO_MSG3 "�ڽ��� ���̳� ���� �ε����� LIFE�� �����մϴ�."
#define INTRO_MSG4 ""
#define INTRO_KEY_START "|���� ���|"
#define INTRO_MSG5 "�ְ� ������ ��� ���� �ִ��� ���� ����(#)�� �Ծ�� �մϴ�."
#define INTRO_MSG6 "SNAKE���̸� �÷� ������ ����ϰ� �����ϼ���!!"

/* �ΰ��� */
#define GAMEOVER_MSG "GAME OVER"
#define GAMEOVER_MSG1 "GAME OVER"
#define LIFE_MSG "LIFE: "
#define SELECT_CONTINUE "1.����ϱ�"
#define SELECT_EXIT "2.�׸��ϱ�"

/*
   ____    _    __  __ _____    _____     _______ ____
  / ___|  / \  |  \/  | ____|  / _ \ \   / / ____|  _ \
 | |  _  / _ \ | |\/| |  _|   | | | \ \ / /|  _| | |_) |
 | |_| |/ ___ \| |  | | |___  | |_| |\ V / | |___|  _ <
  \____/_/   \_\_|  |_|_____|  \___/  \_/  |_____|_| \_\


*/

#include <Windows.h>
#include <stdio.h>
#include <conio.h>

char *ScreenBuffer;

int screenWidth;
int screenHeight;

void setScreenSize(int width, int height);
void setCursorPos(int x, int y);
void SetCursorState(int visible);
void SetColor(unsigned short backGroundColor, unsigned short textColor);

void ClearBuffer();
int WriteToBuffer(int x, int y, const char* str);
int DrawBuffer();