#pragma once

class Paddle
{
public:
    Paddle()
    {
        x = y = 0; // х y направления
    }
    Paddle(int posX, int posY) : Paddle() // х y направления
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }


    inline void Reset() // Для короткий функций, обязывает компилятор думать стоит ли вызывать ну тут стомт
    {
        x = originalX; y = originalY;  // перезагрузка
    }
    inline int getX() const  // получения X  // Для короткий функций, обязывает компилятор думать стоит ли вызывать ну тут стомт
    {
        return x;
    }
    inline int getY() const // поллучения Y  // Для короткий функций, обязывает компилятор думать стоит ли вызывать ну тут стомт
    {
        return y;
    }
    inline void moveUp() // движения в верх  // Для короткий функций, обязывает компилятор думать стоит ли вызывать ну тут стомт
    {
        y--;
    }
    inline void moveDown() // движения в низ  // Для короткий функций, обязывает компилятор думать стоит ли вызывать ну тут стомт
    {
        y++;
    }
private:
    int x, y;
    int originalX, originalY;
};

