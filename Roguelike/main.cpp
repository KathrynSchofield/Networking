#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "World.h"
#include "Network.h"



int main()
{


World TestGame;
Network TestNetwork;

TestGame.Run();
TestNetwork.Start();

return 0;
}
