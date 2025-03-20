#pragma once
#include "cPaddle.hpp"
#include "cBall.hpp"
#include <iostream>
#include <time.h>
#include <conio.h>
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
    
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
    ~cGameManger()
    {
        delete ball, player1, player2;
    }
    void ScoreUp(cPaddle* player)
    {
        if (player == player1)
            score1++;
        else if (player == player2)
            score2++;

        ball->Reset();
        player1->Reset();
        player2->Reset();
    }
    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            std::cout << "\xB2";
        std::cout << std::endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int ballx = ball->getX();
                int bally = ball->getY();
                int player1x = player1->getX();
                int player2x = player2->getX();
                int player1y = player1->getY();
                int player2y = player2->getY();

                if (j == 0)
                    std::cout << "\xB2";

                if (ballx == j && bally == i)
                    std::cout << "O"; //���
                else if (player1x == j && player1y == i)
                    std::cout << "\xDB"; //�����1
                else if (player2x == j && player2y == i)
                    std::cout << "\xDB"; //�����2

                else if (player1x == j && player1y + 1 == i)
                    std::cout << "\xDB"; //�����1
                else if (player1x == j && player1y + 2 == i)
                    std::cout << "\xDB"; //�����1
                else if (player1x == j && player1y + 3 == i)
                    std::cout << "\xDB"; //�����1

                else if (player2x == j && player2y + 1 == i)
                    std::cout << "\xDB"; //�����1
                else if (player2x == j && player2y + 2 == i)
                    std::cout << "\xDB"; //�����1
                else if (player2x == j && player2y + 3 == i)
                    std::cout << "\xDB"; //�����1
                else
                    std::cout << " ";

                if (j == width - 1)
                    std::cout << "\xB2";
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < width + 2; i++)
            std::cout << "\xB2";
        std::cout << std::endl;

        std::cout << "Score 1: " << score1 << std::endl << "Score 2: " << score2 << std::endl;
    }
    void Input()
    {
        ball->Move();

        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        if (_kbhit())
        {
            char current = _getch();
            if (current == up1)
                if (player1y > 0)
                    player1->moveUp();
            if (current == up2)
                if (player2y > 0)
                    player2->moveUp();
            if (current == down1)
                if (player1y + 4 < height)
                    player1->moveDown();
            if (current == down2)
                if (player2y + 4 < height)
                    player2->moveDown();

            if (ball->getDirection() == STOP)
                ball->randomDirection();

            if (current == 'q')
                quit = true;
        }
    }
    void Logic()
    {
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        //����� �����
        for (int i = 0; i < 4; i++)
            if (ballx == player1x + 1)
                if (bally == player1y + i)
                    ball->changeDirection((eDir)((rand() % 3) + 4));

        //������ �����
        for (int i = 0; i < 4; i++)
            if (ballx == player2x - 1)
                if (bally == player2y + i)
                    ball->changeDirection((eDir)((rand() % 3) + 1));

        //������ ������
        if (bally == height - 1)
            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
        //������� ������
        if (bally == 0)
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        //������ �����
        if (ballx == width - 1)
            ScoreUp(player1);
        //����� �����
        if (ballx == 0)
            ScoreUp(player2);
    }
    void Run()
    {
        while (!quit)
        {
            Draw();
            Input();
            Logic();
        }
    }


private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall* ball;
    cPaddle* player1;
    cPaddle* player2;
};

