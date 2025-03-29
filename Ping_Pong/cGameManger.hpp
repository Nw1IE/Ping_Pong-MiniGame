#pragma once
#include "cPaddle.hpp"
#include "cBall.hpp"
#include <iostream>
#include <time.h>
#include <conio.h>    

class cGameManger
{
public:
    cGameManger(int w, int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 'w'; up2 = 'i';
        down1 = 's'; down2 = 'k';
        score1 = score2 = 0;
        width = w; height = h;
        ball = new cBall(w / 2, h / 2);
        player1 = new cPaddle(1, h / 2 - 3);
        player2 = new cPaddle(w - 2, h / 2 - 3);
    }
    ~cGameManger();
    
    void ScoreUp(cPaddle* player); // Повышение очков
   
    void Draw();// Карта
   
    void Input(); // загрузка вход 
     
    void Logic(); // логикарол
    
    void Run();// ускорения


private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall* ball;
    cPaddle* player1;
    cPaddle* player2;
};

