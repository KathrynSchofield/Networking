#include "Queue.h"

Queue::Queue()
{
    //ctor
}

Queue::~Queue()
{
    //dtor
}

void Queue::pop(T& item)
{
    unique_lock<mutex> mlock(mutex_);
    if(queue_.empty())
    {
        return;
    }
    item = queue_.front();
    queue_.pop();
}

void Queue::push(const T& item)
{
    unique_lock<mutex> mlock(mutex_);
    queue_.push(item);
    cond_.notify_one();
}
Queue()=default;
Queue(const Queue&) = delete;
Queue& operator=(cont Queue&) = delete;
