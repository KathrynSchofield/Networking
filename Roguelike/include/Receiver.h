#ifndef RECEIVER_H
#define RECEIVER_H
#include "Queue.h"


class Receiver {
    public:
        Receiver(sf::TcpSocket* s, bool server,Queue<std::string>& queue);
        virtual ~Receiver();
        void recv_loop();

    private:
        sf::TcpSocket* socket;
        bool isServer = false;
        Queue<std::string> &queue;
}

#endif // RECEIVER_H
