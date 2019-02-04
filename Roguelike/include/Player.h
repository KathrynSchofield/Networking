#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

enum class EDirection
{
    eNorth,
    eEast,
    eSouth,
    eWest
};


class Player
{
public:
    Player(Vector2f position);
    virtual ~Player();

    void Move();
    void Render();
    void ChangeDirection(EDirection newDirection);
    CircleShape player;



protected:

private:
    Vector2f playerPosition;
    const float movement = 10.f;
    EDirection direction;

};

#endif // PLAYER_H
