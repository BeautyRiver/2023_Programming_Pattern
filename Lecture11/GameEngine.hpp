#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

namespace MuSoeun
{
    class Component //Unity MonoBehavior
    {
        void Start();
        void Update();
    };

    class Object
    {
    public:
        int x, y;

    public:
        void Render(char* screenBuffer)
        {

        }
    };

    class Scene
    {
    public:
        char* screenBuf;        
        std::vector<Object> objList;


        void InitScreenBuf(int width, int height)
        {
            

            width += 2;
            height += 2;
            screenBuf = new char[(width + 1) * (height)];

            int x = 0; /* 가로 index */
            int y = 0; /* 세로 index */
            while (y < height)
            {
                while (x < width + 1) /* 개행문자때문에 + 1*/
                {
                    if (x == width)
                        screenBuf[x + (y * (width + 1))] = '\n';
                    else
                    {
                        if (x == 0 || x == (width - 1) || y == 0 || y == (height - 1))
                            screenBuf[x + (y * (width + 1))] = '#';
                        else
                            screenBuf[x + (y * (width + 1))] = ' ';
                    }
                    x += 1;
                }

                x = 0;
                y += 1;
            }
            screenBuf[height * (width + 1) - 1] = '\0';

        }
        void ReleaseScreenBuf()
        {
            if (screenBuf != nullptr)
            {
                delete(screenBuf);
            }
        }
        void DrawScreenBuf()
        {
            std::cout << screenBuf;
        }

        void ClearScreenBuf()
        {
            system("cls");
        }
    };
}