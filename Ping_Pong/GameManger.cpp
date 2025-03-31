#include "GameManger.hpp"

GameManger::~GameManger() // типа упр игры
{
    delete ball, player1, player2;
}

void GameManger::ScoreUp(Paddle* player) // Повышение очков
{
    if (player == player1)
        score1++;
    else if (player == player2)
        score2++;

    ball->Reset();
    player1->Reset();
    player2->Reset();
}

void GameManger::Draw() // Карта
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        std::cout << "\xB2";
    std::cout << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ballx = ball->getX(); // спавн
            int bally = ball->getY(); // спавн
            int player1x = player1->getX(); // спавн
            int player2x = player2->getX(); // спавн
            int player1y = player1->getY(); // спавн
            int player2y = player2->getY(); // спавн

            if (j == 0)
                std::cout << "\xB2";

            if (ballx == j && bally == i)
            {
                std::cout << "O"; //мяч
            }
            else if (player1x == j && player1y == i)
            {
                std::cout << "\xDB"; //1 плеер
            }
                
            else if (player2x == j && player2y == i)
            {
                std::cout << "\xDB"; //2 плеер
            }
               
            else if (player1x == j && player1y + 1 == i)
            {
                std::cout << "\xDB"; //1 плеер
            }
            else if (player1x == j && player1y + 2 == i)
            {
                std::cout << "\xDB"; //1 плеер
            }
                
            else if (player1x == j && player1y + 3 == i)
            {
                std::cout << "\xDB"; //1 плеер
            }


            else if (player2x == j && player2y + 1 == i)
            {
                std::cout << "\xDB"; //1 плеер
            }
                
            else if (player2x == j && player2y + 2 == i)
            {
                std::cout << "\xDB"; //1 плеер
            }
               
            else if (player2x == j && player2y + 3 == i)
            {
                std::cout << "\xDB"; //1 плеер
            }
            
            else
            {
                std::cout << " ";
            }

            if (j == width - 1)
            {
                std::cout << "\xB2";
            }
                
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "\xB2";
        std::cout << std::endl;
    }
  

   
}

void GameManger::Input()  // загрузка вход 
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
        {
            if (player1y > 0)
            {
                player1->moveUp();
            }
        }

        if (current == up2)
        {
            if (player2y > 0)
            {
                player2->moveUp();
            }
               
        }

        if (current == down1)
        {
            if (player1y + 4 < height)
            {
                player1->moveDown();
            }
               
        }

        if (current == down2)
        {
            if (player2y + 4 < height)
            {
                player2->moveDown();
            }
        }

        if (ball->getDirection() == STOP)
        {
            ball->randomDirection();
        }

        if (current == 'q')
        {
            quit = true;
        }

    }
}

void GameManger::Logic() // логикарол
{
    int ballx = ball->getX();
    int bally = ball->getY();
    int player1x = player1->getX();
    int player2x = player2->getX();
    int player1y = player1->getY();
    int player2y = player2->getY();

    //левое весло
    for (int i = 0; i < 4; i++)
    {
        if (ballx == player1x + 1)
        {
            if (bally == player1y + i)
            {
                ball->changeDirection((eDir)((rand() % 3) + 4));
            }
        }
    }

    //правое весло
    for (int i = 0; i < 4; i++)
    {
        if (ballx == player2x - 1)
        {
            if (bally == player2y + i)
            {
                ball->changeDirection((eDir)((rand() % 3) + 1));
            }
        }
    }



    //нижняя стенка
    if (bally == height - 1)
    {
        ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
    }

    //верхняя стенка
    if (bally == 0)
    {
        ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
    }

    //правая стена
    if (ballx == width - 1)
    {
        ScoreUp(player1);
    }

    //левая стена
    if (ballx == 0)
    {
        ScoreUp(player2);
    }

}

void GameManger::Run() // ускорения
{

    while (!quit)
    {
        Draw();
        Input();
        Logic();
    }
}
