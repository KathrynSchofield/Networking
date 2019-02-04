#include "World.h"
#include "Player.h"
#include <iostream>
World::World(): window(VideoMode(screenWidth, screenHeight), "SFML works!")
{
    //ctor
}

World::~World()
{
    //dtor
}

void World::Run()
{
    Player playerOne(Vector2f(100.f,100.f));

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::A:
                    playerOne.ChangeDirection(EDirection::eWest);
                    std::cout << "Left" << std::endl;
                    playerOne.Move();
                    break;
                case Keyboard::D:
                    std::cout << "Right" << std::endl;
                    playerOne.ChangeDirection(EDirection::eEast);
                    playerOne.Move();
                    break;
                case Keyboard::S:
                    std::cout << "Down" << std::endl;
                    playerOne.ChangeDirection(EDirection::eSouth);
                    playerOne.Move();
                    break;
                case Keyboard::W:
                    std::cout << "Up" << std::endl;
                    playerOne.ChangeDirection(EDirection::eNorth);
                    playerOne.Move();
                    break;
                default:
                    break;
                }
            default:
                break;

            }
        }





        window.clear();
        window.draw(playerOne.player);
        window.display();

    }

}
