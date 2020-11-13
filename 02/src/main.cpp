#include "executor.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "starting\n";

    ees::Executor e1;
    ees::Executor e2;

    for (int i = 0; i < 10; ++i)
    {
        e1.wait(2000);
        e2.wait(3000);
        e1.print("Hello");
        e2.print("World");
        
    }

    std::cout << "main finished\n";
}
