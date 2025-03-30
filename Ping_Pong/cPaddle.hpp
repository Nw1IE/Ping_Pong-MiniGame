#pragma once

class cPaddle
{
public:
    cPaddle()
    {
        x = y = 0; // � y �����������
    }
    cPaddle(int posX, int posY) : cPaddle() // � y �����������
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
   
    
    inline void Reset() 
    {
        x = originalX; y = originalY;  // ������������
    }
    inline int getX() const  // ��������� X
    {
        return x; 
    }
    inline int getY() const // ���������� Y
    { 
        return y; 
    }
    inline void moveUp() // �������� � ����
    { 
        y--; 
    }
    inline void moveDown() // �������� � ���
    { 
        y++; 
    }
private:
    int x, y;
    int originalX, originalY;
};

