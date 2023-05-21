#include <iostream>
#include "GameEngine.hpp"
using namespace MuSoeun;

int main()
{
	Scene scene;
	int width, height;

	std::cout << "Width >> ";
	std::cin >> width;
	std::cout << "Height >> ";
	std::cin >> height;

	scene.InitScreenBuf(width,height);
	scene.DrawScreenBuf();
	scene.ReleaseScreenBuf();
	return 0;
}
