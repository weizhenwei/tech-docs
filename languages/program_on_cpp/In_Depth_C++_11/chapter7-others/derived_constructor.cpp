#include <string>
#include <iostream>


struct Base {
    int x;
    int y;
    std::string s;

    Base(int i) : x(i), y(0), s("") {
        std::cout << "Base constructor with 1 parameter" << std::endl;
    }
    Base(int i, int j) : x(i), y(j), s("") {
        std::cout << "Base constructor with 2 parameters" << std::endl;
    }
    Base(int i, int j, const std::string& str) : x(i), y(j), s(str) {
        std::cout << "Base constructor with 3 parameters" << std::endl;
    }
};

struct Derived1 : Base {
    Derived1(int i) : Base(i) {
        std::cout << "Derived1 constructor with 1 parameter" << std::endl;
    }
    Derived1(int i, int j) : Base(i, j) {
        std::cout << "Derived1 constructor with 2 parameters" << std::endl;
    }
    Derived1(int i, int j, const std::string& str) : Base(i, j, str) {
        std::cout << "Derived1 constructor with 3 parameters" << std::endl;
    }
};

struct Derived2 : Base {
    // derive constructors from Base;
    using Base::Base;
};

int main(int argc, char *argv[]) {
    int i = 1;
    int j = 2;
    std::string str = "Hello, c++11";

    Derived1 d1(i, j, str);
    Derived2 d2(i, j, str);

    return 0;
}

