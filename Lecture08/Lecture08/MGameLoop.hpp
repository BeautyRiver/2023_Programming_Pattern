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
		//x, y ��ǥ ����
		COORD pos = { x - 1,y - 1 };
		//Ŀ�� �̵�
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
			std::cout << "�ʱ�ȭ �Ϸ�" << std::endl;
		}
		void Release()
		{
			gotoxy(0, 10);
			std::cout << "�ý��� ���� �Ϸ�" << std::endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			std::cout << "������Ʈ��..." << std::endl;

			if (_kbhit())
			{
				KeyEvent(_getch());
			}

		}

		void Render()
		{
			gotoxy(0, 10);
			std::cout << "������ �Ϸ�" << std::endl;
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
			case KEY_LEFT: //a : ����
				gotoxy(2,5);
				std::cout << ANSI_COLOR_YELLOW"������ ���ȴ�!  " << std::endl;
				break;

			case KEY_RIGHT: //d : ������
				gotoxy(2,5);
				std::cout << ANSI_COLOR_YELLOW"�������� ���ȴ�!" << std::endl;
				break;

				/*27: ESC ��������Ű
				�ѹ� �������� �Ͻ�����
				�ι� �������� ��������*/
			case KEY_EXIT:
				isGameRunning = false;
				//24�� 8���� ����
				std::cout << "���� ������ �����Ͻðڽ��ϱ�?" << std::endl;
				break;

			case KEY_ENTER:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"���Ͱ� ���ȴ�!  " << std::endl;
				break;

			default:
				break;
			}
		}
	};
}




