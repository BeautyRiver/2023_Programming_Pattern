#include <iostream>
#include <conio.h>
int main(void)
{
	char ch;	
	while(true)
	{
		std::cout << "Enter ESC!!!\n";
		if (_kbhit())
		{
			ch = _getch();
			std::cout << ch;
			if(ch == 27)
			{
				std::cout << "program exit" <<std::endl;
				break;
			}
		}
	
	}
	return 0;
}

