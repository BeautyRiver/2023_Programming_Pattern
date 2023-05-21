#pragma once
#define DEBUG

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "GameEngine.hpp"

using namespace MuSoeun;

void print_title_screen();
void print_introduction_screen();
void print_game_screen();


char ch;
int is_game_run = 1;		//게임 구동여부
int is_game_starting = 0;	//게임 시작여부
int is_introducing = 0;		//게임 설명여부

void GameLoop()
{
	while (is_game_run)
	{
		//타이틀화면 출력
		print_title_screen();

		ch = _getch();
		if (ch == '1')
			is_game_starting = 1;

		else if (ch == '2')
			is_introducing = 1;

		else if (ch == '3')
		{

		}
		else if (ch == 27 || ch == '4') //ESC (ASCII- 27)		
			is_game_run = 0;


		//1.(게임시작)입력시
		while (is_game_starting)
		{
			print_game_screen();
		}

		//2.(게임설명)입력시		
		while (is_introducing)
		{
			//키 입력을 받아 설명화면을 계속 유지할지 / 타이틀 화면으로 이동할지 결정하는 함수 호출
			print_introduction_screen();
		}
	}
	std::cout << "게임을 종료합니다..." << std::endl;
}

//함수들
//메인화면 출력 함수 / game_state == 0
void print_title_screen()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*               지렁이 게임                *" << std::endl;
	std::cout << "*               (Snake Bite)               *" << std::endl;
	std::cout << "*                                          *" << std::endl;
#ifdef DEBUG 
	std::cout << "*             - 디버그 모드 -              *" << std::endl;
#else
	std::cout << "*                                          *" << std::endl;
#endif // DEBUG
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*  1. 게임 시작                            *" << std::endl;
	std::cout << "*  2. 게임 설명                            *" << std::endl;
	std::cout << "*  3. 게임 랭킹                            *" << std::endl;
	std::cout << "*  4. 게임 종료 (ESC)                      *" << std::endl;
	std::cout << "*  5. 디버그 모드                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "********************************************" << std::endl;


}

//게임시작 출력함수 
void print_game_screen() 
{
	Scene scene;
	scene.InitScreenBuf();
	scene.DrawScreenBuf();
	scene.ReleaseScreenBuf();
}

//게임설명 출력 함수 / game_state == 2
void print_introduction_screen()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*               지렁이 게임                *" << std::endl;
	std::cout << "*               (Snake Bite)               *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*  이 게임은 지렁이를 이동하여             *" << std::endl;
	std::cout << "*  아이템을 먹어, 꼬리길이를 늘려          *" << std::endl;
	std::cout << "*  최대한 오래 생존을 하여 버티는          *" << std::endl;
	std::cout << "*  랭킹경쟁을 목표로 하는 게임입니다.      *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*  타이틀 화면으로 돌아갈까요? (Y/N)       *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "********************************************" << std::endl;

	ch = _getch();
	if (ch == 'Y' || ch == 'y')
	{
		std::cout << "타이틀 화면으로 돌아갑니다." << std::endl;
		is_introducing = 0;
	}
	else if (ch == 'N' || ch == 'n')
	{
		std::cout << "타이틀 화면으로 돌아가지 않았습니다.\n" << std::endl;
		is_introducing = 1;
	}
	else
	{
		std::cout << "(Y/N)중에서 선택해주세요.\n" << std::endl;
	}
}
