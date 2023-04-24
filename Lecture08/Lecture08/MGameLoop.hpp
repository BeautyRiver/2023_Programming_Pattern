#pragma once //#define _IS_THIS_HEADER_INCLUDED 
#define KEY_EXIT 27
#define KEY_RIGHT 'd'
#define KEY_LEFT 'a'
#define KEY_ENTER 13

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
namespace MuSoeun
{
	void gotoxy(int x, int y) {
		//x, y 좌표 설정
		COORD pos = { x - 1,y - 1 };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
	}

	class MGameLoop
	{
	public:
		bool isGameRunning = false;
		MGameLoop() {}
		~MGameLoop() {}
		void Initialize()
		{
			isGameRunning = true;
			gotoxy(0, 10);
			std::cout << "초기화 완료" << std::endl;
		}
		void Release()
		{
			gotoxy(0, 10);
			std::cout << "시스템 해제 완료" << std::endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			std::cout << "업데이트중..." << std::endl;

			if (_kbhit())
			{
				KeyEvent(_getch());
			}

		}

		void Render()
		{
			gotoxy(0, 10);
			std::cout << "렌더링 완료" << std::endl;
		}

		void Run()
		{
			Initialize();
			while (isGameRunning)
			{
				Update();
				Render();
			}
			Release();
		}

		void KeyEvent(char keyInput)
		{
			switch (keyInput)
			{
			case KEY_LEFT: //a : 왼쪽
				gotoxy(2,5);
				std::cout << ANSI_COLOR_YELLOW"왼쪽이 눌렸다!  " << std::endl;
				break;

			case KEY_RIGHT: //d : 오른쪽
				gotoxy(2,5);
				std::cout << ANSI_COLOR_YELLOW"오른쪽이 눌렸다!" << std::endl;
				break;

				/*27: ESC 게임종료키
				한번 눌렀을땐 일시정지
				두번 눌렀을땐 게임종료*/
			case KEY_EXIT:
				isGameRunning = false;
				//24일 8주차 과제
				std::cout << "정말 게임을 종료하시겠습니까?" << std::endl;
				break;

			case KEY_ENTER:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"엔터가 눌렸다!  " << std::endl;
				break;

			default:
				break;
			}
		}
	};
}




