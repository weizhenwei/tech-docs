#include <iostream>
#include <type_traits>

int fn(int) {
    return int();
}
typedef int(&fn_ref)(int);
typedef int(*fn_ptr)(int);
struct fn_class {
    int operator() (int i) {
        return i;
    }
};

int main(void) {
    // hard to understand;
    typedef std::result_of<decltype(fn)&(int)>::type A;
    typedef std::result_of<fn_ref(int)>::type B;
    typedef std::result_of<fn_ptr(int)>::type C;
    typedef std::result_of<fn_class(int)>::type D;

    std::cout << std::boolalpha;
    std::cout << "typedefs of int:" << std::endl;
    std::cout << "is_same<int, A>: " << std::is_same<int, A>::value << std::endl;
    std::cout << "is_same<int, B>: " << std::is_same<int, B>::value << std::endl;
    std::cout << "is_same<int, C>: " << std::is_same<int, C>::value << std::endl;
    std::cout << "is_same<int, D>: " << std::is_same<int, D>::value << std::endl;

    return 0;
}


