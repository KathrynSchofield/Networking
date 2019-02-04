#include "Network.h"
using namespace std;
using namespace sf;
Network::Network()
{
    //ctor
}

Network::~Network()
{
    //dtor
}
/*
void Network::Start()
{
    cout<< "Press 1 for client or 2 for server " <<endl;
    char input;
    cin>> input;

    input -= 48;

    if (input == 2)
    {
        cout<< "2" <<endl;
        Server();
    }
    else if(input == 1)
    {
        cout<< "1" <<endl;
        Client();
    }
}



void Network::Server()
{
    sf::UdpSocket socket;
    if (socket.bind(4300) != sf::Socket::Done)
    {
        cerr<< "Fail bind to port" <<endl;
    }

    cout<< "Server " <<endl;
    char buffer[256];
    size_t received;
    IpAddress sender;
    unsigned short sender_port;
    if (socket.receive(buffer, 256, received, sender, sender_port) != sf::Socket::Done)
        cerr<< "Failed to receive data" <<endl;


    std::cout << "Received: " << buffer << std::endl;
:recv_loop()
    if (socket.send(buffer, received, sender, sender_port)!= sf::Socket::Done)
        cerr<< "Fail sending data" <<endl;

}
void Network::Client()
{

    cout<< "Client" <<endl;
    UdpSocket socket;

    char buffer[256] = "Message to send";
    sf::IpAddress recipient = "localhost";
    unsigned short remote_port {4300};
    size_t received;
    if (socket.send(buffer, sizeof(buffer),recipient, remote_port)!= sf::Socket::Done)
        cerr<< "Fail sending data to host" <<endl;

    if (socket.receive(buffer, 256, received, recipient, remote_port) != sf::Socket::Done)
        cerr<< "Failed to receive data" <<endl;
    std::cout << "Received: " << buffer << std::endl;
}
*/

//chat server






void Network::recv_loop()
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
void Network::accepter(Queue<string> &queue, list<TcpSocket*> &sockets,mutex &m)
{
    TcpListener listner;
    Socket::Status status = listner.listen(4300);
    if (status != Socket::Done)
    {
        cerr<<"Listen:" << status << endl;
        return;
    }
    while (1)
    {
        TcpSocket *socket = new TcpSocket;
        status = listner.accept(*socket);

        {
            unique_lock<mutex> l(m);
            sockets.push_back(socket);
        }
        if (status != Socket::Done)
        {
            carr <<"Accept:" << status << endl;
            return;
        }
        Receiver *r = new Receiver(socket, true, queue);
        thread([r] {r->recv_loop();}).detach();
    }

}

void Network::server_main();
{
    Queue<std::string> queue;
    std::mutex m;
    std::list<sf::TcpSocket*> sockets;
    std::thread(accepter,
                std::ref(queue),
                std::ref(sockets),
                std::ref(m)).detach();
    while(1)
    {
        std::string s = queue.pop();
        std::cout << "Main read: '" << s << "'\n";
        {
            std::unique_lock<std::mutex> l(m);
            for (auto socket : sockets)
            {
                sf::Socket::Status status = socket->send(s.c_str(), s.size());
                if (status != sf::Socket::Done)
                {
                    std::cout << "Sending failed: " << status << std::endl;
                }
            }
        }
    }
    return 0;
}




















