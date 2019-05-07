#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

class Queue //used to shared received messages
{
public:
    Queue();
    virtual ~Queue();

    T pop() //like bounded buffers, useful for send threads
    {
        unique_lock<mutex> mlock(mutex_);
        cond_.wait(mlock, [this] {return !queue_.empty();});
        auto val = queue_.front();
        queue_.pop();
        return val;
    }
    void pop(T& item) //returns on an empty queue
    {
        unique_lock<mutex> mlock(mutex_);
        if(queue_.empty())
        {
            return;
        }
        item = queue_.front();
        queue_.pop();
    }

    void push(const T& item) //stops waiting on the full list condition
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
