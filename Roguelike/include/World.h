#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

class World
{
public:
    World();
    virtual ~World();

    void Run();

protected:

private:
    int screenWidth {700};
    int screenHeight{500};
    RenderWindow window;
};

#endif // WORLD_H
