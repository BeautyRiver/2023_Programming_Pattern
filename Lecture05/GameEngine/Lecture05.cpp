#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

void print_title_screen();
void print_introduction_screen();

void gotoxy(int x, int y)
{
	//x,y 좌표 설정	

}

int main()
{
	char ch;
	int game_state = 0;
	int is_game_running = 1;
	//교수님 코드    
	//while (is_game_running)
	//{
	//    char key_input = '0';
	//    switch (game_state)
	//    {
	//    case 0:
	//        //메인화면 출력 함수 호출
	//        print_title_screen();
	//        key_input = _getch();
	//        switch (key_input)
	//        {
	//        case '1':
	//            break;
	//        case '2':
	//            game_state = 2;
	//            break;
	//        case '3':
	//            break;
	//        case '4':
	//            is_game_running = 0;
	//			  std::cout << "게임을 종료합니다..." << std::endl;
	//            break;
	//        case 27:
	//            is_game_running = 0;
	//        default:
	//            break;
	//        }
	//        break;

	//    case 2:
	//        print_introduction_screen();
	//        key_input = _getch();
	//        switch (key_input)
	//        {
	//        case 'y':
	//        case 'Y':
	//            game_state = 0;
	//            break;
	//        case 'n':
	//        case 'N':
	//            std::cout << "타이틀 화면으로 돌아가지 않았습니다.\n" << std::endl;

	//            break;
	//        default:
	//            break;
	//        }
	//        break;
	//    default:
	//        std::cout << "(Y/N)중에서 선택해주세요.\n" << std::endl;
	//        break;
	//    }
	//}
	//내 코드

	while (1)
	{
		print_title_screen();
		ch = _getch();
		//2(게임설명) 입력시
		if (ch == '2')
		{
			while (1)
			{
				//키 입력을 받아 설명화면을 계속 유지할지 / 타이틀 화면으로 이동할지 결정
				print_introduction_screen();
				ch = _getch();
				if (ch == 'Y' || ch == 'y')
				{
					break;
				}
				else if (ch == 'N' || ch == 'n')
				{
					std::cout << "타이틀 화면으로 돌아가지 않았습니다.\n" << std::endl;
					continue;
				}
				else
				{
					std::cout << "(Y/N)중에서 선택해주세요.\n" << std::endl;
				}
			}
		}
		//ESC (ASCII- 27) || 4 입력시 반복문 종료
		else if (ch == 27 || ch == '4')
		{
			std::cout << "게임을 종료합니다..." << std::endl;
			break;
		}
	}
	return 0;
}

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
}