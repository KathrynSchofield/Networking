 #ifndef NETWORK_H
#define NETWORK_H
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
using namespace sf;

class Network
{
public:
    Network(TcpSocket* s, bool server, queue<string>& queue));
    virtual ~Network();

    void Start();
    void Server();
    void Client();

    void recv_loop();
    void accepter(Queue<string> &queue, list<TcpSocket*> &sockets,mutex &m)
    void server_main();

private:
    TcpSocket* socket;
    bool isServer = false;
    queue<string> &queue;
};

#endif // NETWORK_H
