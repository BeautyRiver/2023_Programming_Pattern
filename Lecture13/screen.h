#pragma once
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//맵 크기
#define MAP_WIDTH 70
#define MAP_HEIGHT 20

//메시지
/* 타이틀 */
#define TITLE_MSG "SNAKE GAME"
#define TITLE_MSG1 "       _____ _   _____    __ __ ______   _________    __  _________"
#define TITLE_MSG2 "     / ___// | / /   |  / //_// ____/  / ____/   |  /  |/  / ____/"
#define TITLE_MSG3 "  \\__ \\/  |/ / /| | / ,<  / __/    / / __/ /| | / /|_/ / __/"
#define TITLE_MSG4 " ___/ / /|  / ___ |/ /| |/ /___   / /_/ / ___ |/ /  / / /___"
#define TITLE_MSG5 "/____/_/ |_/_/  |_/_/ |_/_____/   \\____/_/  |_/_/  /_/_____/"

#define TITLE_MENU1 "1.게임 시작"
#define TITLE_MENU2 "2.게임 설명"
#define TITLE_MENU3 "3.게임 랭킹"
#define TITLE_MENU4 "4.게임 종료"

/* 게임설명 */
#define INTRO_START "|게임 설명|"
#define INTRO_MSG1 "SNAKE GAME은 뱀을 조종하여 과일(#)을 먹고"
#define INTRO_MSG2 "뱀을 점점 길어지게 만드는 게임입니다."
#define INTRO_MSG3 "벽에 부딪히면 LIFE가 감소합니다."
#define INTRO_MSG4 "하지만 자신의 몸에 부딪힐시 뱀은 즉사하게 됩니다."
#define INTRO_MSG5 "LIFE가 0이 될시 GAME OVER가 됩니다."
#define INTRO_MSG6 "뱀의 길이를 늘려 순위를 기록하고 경쟁하세요!!"

#define INTRO_KEY_START "|조작 방법|"
#define INTRO_KEY_MSG1 "ESC(인게임내) - 일시정지"
#define INTRO_KEY_MSG2 "키보드 방향키(상,하,좌,우)"
#define INTRO_KEY_MSG3 "상하좌우 이동"

/* 인게임 */
#define GAMEOVER_MSG "GAME OVER"
#define GAMEOVER_MSG1 "GAME OVER"
#define ENTER_NAME "Please enter your name: "
#define LIFE_MSG "LIFE: "
#define SELECT_CONTINUE "1.계속하기"
#define SELECT_RESTART "1.다시하기"
#define SELECT_EXIT "2.그만하기"

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