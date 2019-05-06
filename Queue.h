#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
using namespace sf;

class Queue
{
    public:
        Queue();
        virtual ~Queue();

        T pop()
        {
            unique_lock<mutex> mlock(mutex_);
            cond_.wait(mlock, [this]{return !queue_.empty();});
            auto val = queue_.front();
            queue_.pop();
            return val;
        }
        void push(const T& item)

    protected:

    private:
        queue<T> queue_;
        mutex mutex_;
        condition_variable cond_;

};

#endif // QUEUE_H
