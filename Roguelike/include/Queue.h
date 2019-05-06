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
        cond_.wait(mlock, [this] {return !queue_.empty();});
        auto val = queue_.front();
        queue_.pop();
        return val;
    }
    void pop(T& item)
    {
        unique_lock<mutex> mlock(mutex_);
        if(queue_.empty())
        {
            return;
        }
        item = queue_.front();
        queue_.pop();
    }

    void ush(const T& item)
    {
        unique_lock<mutex> mlock(mutex_);
        queue_.push(item);
        cond_.notify_one();
    }
    Queue()=default;
    Queue(const Queue&) = delete;
    Queue& operator=(cont Queue&) = delete;

protected:

private:
    queue<T> queue_;
    mutex mutex_;
    condition_variable cond_;

};

#endif // QUEUE_H
