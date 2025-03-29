#include "cBall.hpp"

//�������
void cBall::Reset() // ������� ������
{
    x = originalX; y = originalY;
    direction = STOP;
}
void cBall::changeDirection(eDir d) // ��������� �����������
{
    direction = d;
}
void cBall::randomDirection() // ��������� �����������
{
    direction = (eDir)((rand() % 6) + 1);
}

//�������
inline int cBall::getX() // ����� ������ �������
{
    return x;
}
inline int cBall::getY() // ����� ������ �������
{
    return y;
}
inline eDir cBall::getDirection() // ����� ������ �����������
{
    return direction;
}
void cBall::Move() // ��������
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