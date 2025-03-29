#include "cBall.hpp"

//геттеры
void cBall::Reset() // респавн мячика
{
    x = originalX; y = originalY;
    direction = STOP;
}
void cBall::changeDirection(eDir d) // изменения направления
{
    direction = d;
}
void cBall::randomDirection() // случайное направления
{
    direction = (eDir)((rand() % 6) + 1);
}

//сеттеры
inline int cBall::getX() // точка вызова функции
{
    return x;
}
inline int cBall::getY() // точка вызова функции
{
    return y;
}
inline eDir cBall::getDirection() // точка вызова направленмя
{
    return direction;
}
void cBall::Move() // движения
{
    switch (direction)
    {
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--; y--;
        break;
    case DOWNLEFT:
        x--; y++;
        break;
    case UPRIGHT:
        x++; y--;
        break;
    case DOWNRIGHT:
        x++; y++;
        break;
    default:
        break;
    }
}