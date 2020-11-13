#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

namespace ees
{

template<typename T>
class SafeQueue
{
public:
    void enqueue(T t)
    {
        std::scoped_lock l(m);
        q.push(t);
        cv.notify_one();
    }

    T dequeue()
    {
        std::unique_lock l(m);
        while (q.empty())
        {
            cv.wait(l);
        }
        auto t = q.front();
        q.pop();
        return t;
    }

private:
    std::queue<T> q;
    std::mutex m;
    std::condition_variable cv;
};

}

#endif
