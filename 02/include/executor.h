#include <chrono>
#include <string>
#include <iostream>
#include "active_obj.h"

namespace ees
{

class Executor
{
public:
    void print(const std::string &str)
    {
        active.post([=](){
            std::cout << str << std::endl;
        });
    }

    void wait(int millis)
    {
        active.post([=](){
            std::this_thread::sleep_for(std::chrono::milliseconds(millis));
        });
    }

private:
    ActiveObject active;
};

}
