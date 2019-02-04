#include "Player.h"
#include <iostream>

Player::Player(Vector2f position): player(10.f), playerPosition(position)
{
    player.setFillColor(Color::Yellow);
    player.setPosition(position);
    //ctor
}

Player::~Player()
{
    //dtor
}


void Player::Move()
{
    switch(direction)
    {
    case EDirection::eNorth:
        playerPosition.y-=movement;
        std::cout << "Up" << std::endl;
        break;
    case EDirection::eEast:
        playerPosition.x+=movement;
        std::cout << "Right" << std::endl;
        break;
    case EDirection::eSouth:
        playerPosition.y+=movement;
        std::cout << "Down" << std::endl;
        break;
    case EDirection::eWest:
        playerPosition.x-=movement;
        std::cout << "Left" << std::endl;
        break;
    }
    player.setPosition(playerPosition);
    std::cout << "X Pos: " << playerPosition.x << " Y Pos: " << playerPosition.y << std::endl;
}

void Player::ChangeDirection(EDirection newDirection)
{
    direction=newDirection;
    std::cout << "Changing direction" << endl;
}



