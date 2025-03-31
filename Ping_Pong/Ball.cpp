#include "Ball.hpp"

//геттеры
void Ball::Reset() // респавн мячика
{
    x = originalX; y = originalY;
    direction = STOP;
}
void Ball::changeDirection(eDir d) // изменения направления
{
    direction = d;
}
void Ball::randomDirection() // случайное направления
{
    direction = (eDir)((rand() % 6) + 1);
}

//сеттеры
int Ball::getX() // точка вызова функции
{
    return x;
}
int Ball::getY() // точка вызова функции
{
    return y;
}
eDir Ball::getDirection() // точка вызова направленмя
{
    return direction;
}
void Ball::Move() // движения управления
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