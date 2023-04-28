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
	//x축 y축 이동
	void gotoxy(int x, int y)
	{
		//x, y 좌표 설정
		COORD pos = { x - 1,y - 1 };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	//Cursor 상태
	void SetCursorState(bool visible)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = visible;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
	}

	class MGameLoop
	{
	public:
		bool isGameRunning = false;
		bool isRendering = false;
		MGameLoop() {}
		~MGameLoop() {}

		//초기화
		void Initialize()
		{
			SetCursorState(false);

			gotoxy(3, 15);
			std::cout << ANSI_COLOR_RESET"게임 초기화" << std::endl;
			isGameRunning = true;
		}

		//종료
		void Release()
		{
			gotoxy(3, 18);			
			std::cout << ANSI_COLOR_RESET"게임 종료중" << std::endl;
		}

		//업데이트
		void Update()
		{
			gotoxy(3, 16);
			std::cout << ANSI_COLOR_RESET"게임 키입력 대기" << std::endl;
			if (_kbhit())
			{
				KeyEvent(_getch());
			}
		}
		//렌더링
		void Render()
		{
			gotoxy(3, 17);
			std::cout << "게임 화면 그리기" << std::endl;
		}

		//실행문
		void Run()
		{
			Initialize();
			while (isGameRunning)
			{
				Update();
				if (isRendering)
					Render();
			}
			Release();
		}

		void KeyEvent(char keyInput)
		{
			switch (keyInput)
			{
			case KEY_LEFT: //a : 왼쪽
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"왼쪽이 눌렸다!  " << std::endl;
				break;

			case KEY_RIGHT: //d : 오른쪽
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"오른쪽이 눌렸다!" << std::endl;
				break;

				/*27: ESC 게임종료키
				한번 눌렀을땐 일시정지
				두번 눌렀을땐 게임종료*/

			case KEY_EXIT:
			{
				char decideExit;
				bool isExitYes = false;
				//24일 8주차 과제
				system("cls");
				std::cout << "정말 게임을 종료하시겠습니까?" << std::endl;
				gotoxy(1, 10);
				std::cout << "[예]" << std::endl;
				gotoxy(10, 10);
				std::cout << "[아니요]" << std::endl;

				while (isGameRunning)
				{
					decideExit = _getch(); //a,d 입력					
					switch (decideExit)
					{
					case KEY_LEFT: //a : 왼쪽
						gotoxy(1, 10);
						std::cout << ANSI_COLOR_YELLOW"[예]" << std::endl;	//활성화된 메뉴 노란색

						gotoxy(10, 10);
						std::cout << ANSI_COLOR_RESET"[아니요]" << std::endl;	//비활성화 메뉴 원래 색상

						isExitYes = true;	

						break;

					case KEY_RIGHT: //d : 오른쪽
						gotoxy(10, 10);
						std::cout << ANSI_COLOR_YELLOW"[아니요]" << std::endl;	//활성화된 메뉴 노란색

						gotoxy(1, 10);
						std::cout << ANSI_COLOR_RESET"[예]" << std::endl;	//비활성화 메뉴 원래 색상
						isExitYes = false;	

						break;

					case KEY_ENTER:	//엔터키를 입력했을때
						if (isExitYes)	//isExitYes가 참일때 게임종료
						{
							system("cls");
							isGameRunning = false;
						}

						else	//isExitYes가 거짓일때 message출력되면서 게임 계속 실행
						{
							std::cout << ANSI_COLOR_GREEN"\r[아니요]를 선택하였습니다.";
						}

						break;
					default:
						break;
					}
				}
			}
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




