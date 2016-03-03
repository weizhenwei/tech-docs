/*
 * Abstract: test c++ std::function and std::bind()
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 */

#include <iostream>
#include <functional>

void func(void) {
    std::cout << __FUNCTION__ << std::endl;
}

class Foo {
public:
    static int foo_func(int a) {
        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
        return a;
    }
};

class Bar {
public:
    int operator() (int a) {
        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
        return a;
    }
};

class A {
    std::function<void(void)> callback_;
public:
    A(const std::function<void(void)>& f) : callback_(f) {}

    void notify(void) {
        callback_();
    }
};

class FFoo {
public:
    void operator() (void) {
        std::cout << __FUNCTION__ << "() ->: " << std::endl;
    }
};


int main(void) {
    // bind to a general function;
    std::function<void(void)> fr1 = func;
    fr1();

    // bind a class static function;
    std::function<int(int)> fr2 = Foo::foo_func;
    std::cout << fr2(123) << std::endl;

    // bind a like function;
    Bar bar;
    fr2 = bar;
    std::cout << fr2(456) << std::endl;

    FFoo ffoo;
    A aa(ffoo);
    aa.notify();

    return 0;
}

