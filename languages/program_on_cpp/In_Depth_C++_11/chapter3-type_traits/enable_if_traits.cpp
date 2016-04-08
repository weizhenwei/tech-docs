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


template <class T>
typename std::enable_if<std::is_arithmetic<T>::value, std::string>::type toString(const T &t) {
    return std::to_string(t);

}

#if 0
template <class T>
typename std::enable_if<!std::is_same<T, std::string>::value, std::string>::type toString(const T &t) {
    return t;
}
#endif


int main(void) {
    fool1(12);
    fool1("good");

    fool2(1);
    fool2("23");

    std::string str;
    str = toString(234324);
    std::cout << str << std::endl;
    // str = toString("134234235235");
    std::cout << str << std::endl;

    return 0;
}



