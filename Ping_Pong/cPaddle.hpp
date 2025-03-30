#pragma once

class cPaddle
{
public:
    cPaddle()
    {
        x = y = 0; // х y направления
    }
    cPaddle(int posX, int posY) : cPaddle() // х y направления
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
   
    
    inline void Reset() 
    {
        x = originalX; y = originalY;  // перезагрузка
    }
    inline int getX() const  // получения X
    {
        return x; 
    }
    inline int getY() const // поллучения Y
    { 
        return y; 
    }
    inline void moveUp() // движения в верх
    { 
        y--; 
    }
    inline void moveDown() // движения в низ
    { 
        y++; 
    }
private:
    int x, y;
    int originalX, originalY;
};

