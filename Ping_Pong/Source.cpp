#include "Ball.hpp"
#include "GameManger.hpp"
#include "Paddle.hpp"
int main()
{
    GameManger c(20, 10); // Карта и показ игроков, типа как бы управления
    c.Run(); // все относиться к ускорению, к загрузке карты 
    return 0;
}

// IK левый, WS правый