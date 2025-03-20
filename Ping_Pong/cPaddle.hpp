#pragma once
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
class cPaddle
{
public:
    cPaddle()
    {
        x = y = 0;
    }
    cPaddle(int posX, int posY) : cPaddle()
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
    inline void Reset() { x = originalX; y = originalY; }
    inline int getX() { return x; }
    inline int getY() { return y; }
    inline void moveUp() { y--; }
    inline void moveDown() { y++; }
private:
    int x, y;
    int originalX, originalY;
};

