#pragma once
#include <random>

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class cBall
{
public:
    cBall(int posX, int posY) 
    {
        originalX = posX;
        originalY = posY;
        x = posX; y = posY;
        direction = STOP;
    }
   
    void Reset(); // респавн мячика
    void changeDirection(eDir d); // изменения направления
    void randomDirection(); // случайное направления
    
    inline int getX(); // точка вызова функции
    
    inline int getY(); // точка вызова функции
    inline eDir getDirection() ;// точка вызова направленмя
    void Move(); // движения

private:
    int x, y;
    int originalX, originalY;
    eDir direction;
};

