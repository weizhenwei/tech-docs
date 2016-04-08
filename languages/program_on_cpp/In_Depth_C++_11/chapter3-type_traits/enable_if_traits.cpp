#include <iostream>
#include <type_traits>
#include <typeinfo>

template <class T>
typename std::enable_if<std::is_arithmetic<T>::value, int>::type fool1(T t) {
        std::cout << t << std::endl;
        return 0;
}

template <class T>
typename std::enable_if<!std::is_arithmetic<T>::value, int>::type fool1(T &t) {
        std::cout << typeid(T).name() << std::endl;
        std::cout << t << std::endl;

        return 1;
}

template <class T>
typename std::enable_if<std::is_arithmetic<T>::value>::type fool2(T t) {
        std::cout << typeid(T).name() << std::endl;
        std::cout << t << std::endl;
}

template <class T>
typename std::enable_if<!std::is_arithmetic<T>::value>::type fool2(T t) {
        std::cout << typeid(T).name() << std::endl;
        std::cout << t << std::endl;
}

int main(void) {
    fool1(12);
    fool1("good");

    fool2(1);
    fool2("23");

    return 0;
}



