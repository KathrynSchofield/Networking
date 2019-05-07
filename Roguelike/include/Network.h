#ifndef NETWORK_H
#define NETWORK_H
#include "Queue.h"
#include <iostream>
#include <SFML/Network.hpp>
template <typename T>
using namespace sf;
using namespace std;

class Network
{
public:
    Network();
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
