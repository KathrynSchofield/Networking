#include "Receiver.h"

Receiver::Receiver(sf::TcpSocket* s, bool server,Queue<std::string>& queue))
{
    //ctor
}

Receiver::~Receiver()
{
    //dtor
}

void Receiver::recv_loop()
{
    char buffer[256];
    while(1)
    {
        memset(buffer, 0, 256);
        size_t received;
        Socket::Status status = socket->receive(buffer, 256, received);
        if (status != Socket::Done)
        {
            perror("Receive");
            cerr << "Receive:" << status << endl;
            return;
        }

        if (ifServer)
        {
            queue.push(string(buffer));
        }
    }
}
