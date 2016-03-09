/*
 * test c++11 weak_ptr
 * change line 25 to std::shared_ptr<A> aptr; to see the memory leak!
 * Author: weizhenwei
 */

#include <iostream>
#include <memory>


struct A;
struct B;

struct A {
public:
    A() { std::cout << "A() constructor" << std::endl; }
    ~A() { std::cout << "~A() destructor" << std::endl; }
    std::shared_ptr<B> bptr;
};

struct B {
public:
    B() { std::cout << "B() constructor" << std::endl; }
    ~B() { std::cout << "~B() destructor" << std::endl; }
    std::weak_ptr<A> aptr;  // use weak_ptr to avoid the memory leak!
};

int main(int argc, char *argv[]) {
    {
        std::shared_ptr<A> ap = std::make_shared<A>();
        std::shared_ptr<B> bp = std::make_shared<B>();
        ap->bptr = bp;
        bp->aptr = ap;
    }

    return 0;
}

