#include <iostream>
#include <iomanip>
#include "fmt/format.h"

namespace ees
{

/**
 * An interface is just a class with only virtual abstract (= 0) methods
 */
class MyInterface
{
public:
    virtual void print_all_formats(int num) = 0;
    /**
     * Everytime a class has one virtual method it must have a virtual destructor
     * otherwise the class may be wrongly destructed when accessed by
     * a pointer to the base class
     */
    ~MyInterface() = default;
};

class MyImplementation : public MyInterface
{
public:
    void print_all_formats(int num) {
        fmt::print("int: {0:d}; hex: {0:x}; oct:{0:o}; bin:{0:b}", num);
    }
};

}

int main(int argc, char* argv[])
{
    std::unique_ptr<ees::MyInterface> m = std::make_unique<ees::MyImplementation>();
    m->print_all_formats(42);
}
