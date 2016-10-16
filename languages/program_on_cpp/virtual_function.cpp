#include <iostream>

class Base {
public:
    Base(int _a) : a(_a) {}
    int a;

    // if no virtual function defined at Base class define,
    // there will  be compile error:
    // virtual_function.cpp:27:9: error: no member named 'Print' in 'Base'
    //        bp->Print();
    //    ~~  ^
    // REASON:
    // “如果调用非虚函数，则无论实际对象是什么类型，都执行基类类型所定义的函数。”
    // –《C++ Primer》第四版中文版480页
    // virtual void Print() {}
};

class Derived : public Base {
public:
    Derived(int _a) : Base(_a) {}

    void Print() {
        std::cout << "a = " << a << std::endl;
    }
};

int main(int argc, char *argv[]) {
    Derived d(5);
    Base *bp = &d;

    bp->Print();

    return 0;
}

