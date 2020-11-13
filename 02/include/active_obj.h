#pragma once

#include "safe_queue.h"
#include <functional>
#include <thread>

namespace ees
{

    class ActiveObject
    {
    public:
        ActiveObject() : running(true), q(), t(&ActiveObject::run, this) {}
        ~ActiveObject() {
            post([&]() { running = false; });
            t.join();
        }

        void post(std::function<void(void)> f)
        {
            q.enqueue(f);
        }

    private:
        bool running;
        SafeQueue<std::function<void(void)>> q;
        std::thread t;

        void run()
        {
            while (running)
            {
                auto f = q.dequeue();
                f();
            }
        }
    };

}
