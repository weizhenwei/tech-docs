
#include <iostream>
#include <type_traits>
#include <memory>

int main(void) {
    typedef typename std::conditional<true, int, double>::type A;
    A a;
    if (std::is_integral<A>::value) {
        a = 12;
    } else if (std::is_floating_point<A>::value) {
        a = 12.345;
    }
    std::cout << a << std::endl;

    using MaxSizeType = typename std::conditional<(sizeof(long int) > sizeof(long double)),
          long int, long double>::type;
    std::cout << typeid(MaxSizeType).name() << std::endl;

    return 0;
}

