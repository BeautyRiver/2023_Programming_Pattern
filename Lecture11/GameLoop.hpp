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
int is_game_run = 1;		//���� ��������
int is_game_starting = 0;	//���� ���ۿ���
int is_introducing = 0;		//���� ������

void GameLoop()
{
	while (is_game_run)
	{
		//Ÿ��Ʋȭ�� ���
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


		//1.(���ӽ���)�Է½�
		while (is_game_starting)
		{
			print_game_screen();
		}

		//2.(���Ӽ���)�Է½�		
		while (is_introducing)
		{
			//Ű �Է��� �޾� ����ȭ���� ��� �������� / Ÿ��Ʋ ȭ������ �̵����� �����ϴ� �Լ� ȣ��
			print_introduction_screen();
		}
	}
	std::cout << "������ �����մϴ�..." << std::endl;
}

//�Լ���
//����ȭ�� ��� �Լ� / game_state == 0
void print_title_screen()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*               ������ ����                *" << std::endl;
	std::cout << "*               (Snake Bite)               *" << std::endl;
	std::cout << "*                                          *" << std::endl;
#ifdef DEBUG 
	std::cout << "*             - ����� ��� -              *" << std::endl;
#else
	std::cout << "*                                          *" << std::endl;
#endif // DEBUG
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*  1. ���� ����                            *" << std::endl;
	std::cout << "*  2. ���� ����                            *" << std::endl;
	std::cout << "*  3. ���� ��ŷ                            *" << std::endl;
	std::cout << "*  4. ���� ���� (ESC)                      *" << std::endl;
	std::cout << "*  5. ����� ���                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "********************************************" << std::endl;


}

//���ӽ��� ����Լ� 
void print_game_screen() 
{
	Scene scene;
	scene.InitScreenBuf();
	scene.DrawScreenBuf();
	scene.ReleaseScreenBuf();
}

//���Ӽ��� ��� �Լ� / game_state == 2
void print_introduction_screen()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*               ������ ����                *" << std::endl;
	std::cout << "*               (Snake Bite)               *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*  �� ������ �����̸� �̵��Ͽ�             *" << std::endl;
	std::cout << "*  �������� �Ծ�, �������̸� �÷�          *" << std::endl;
	std::cout << "*  �ִ��� ���� ������ �Ͽ� ��Ƽ��          *" << std::endl;
	std::cout << "*  ��ŷ������ ��ǥ�� �ϴ� �����Դϴ�.      *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "*  Ÿ��Ʋ ȭ������ ���ư����? (Y/N)       *" << std::endl;
	std::cout << "*                                          *" << std::endl;
	std::cout << "********************************************" << std::endl;

	ch = _getch();
	if (ch == 'Y' || ch == 'y')
	{
		std::cout << "Ÿ��Ʋ ȭ������ ���ư��ϴ�." << std::endl;
		is_introducing = 0;
	}
	else if (ch == 'N' || ch == 'n')
	{
		std::cout << "Ÿ��Ʋ ȭ������ ���ư��� �ʾҽ��ϴ�.\n" << std::endl;
		is_introducing = 1;
	}
	else
	{
		std::cout << "(Y/N)�߿��� �������ּ���.\n" << std::endl;
	}
}
