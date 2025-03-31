#pragma once
#include <random>

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 }; // нужно дл€ считывани€ клавишь

class Ball
{
public:
    Ball(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX; y = posY;
        direction = STOP;
    }

    void Reset(); // респавн м€чика
    void changeDirection(eDir d); // изменени€ направлени€
    void randomDirection(); // случайное направлени€

    int getX(); // точка вызова функции

    int getY(); // точка вызова функции
    eDir getDirection();// точка вызова направленм€
    void Move(); // движени€

private:
    int x, y;
    int originalX, originalY;
    eDir direction;
};

