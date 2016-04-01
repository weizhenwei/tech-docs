#include <iostream>
#include <type_traits>

struct A {};
struct B : A {};
struct C : B {};
struct D {};

int main(void) {
    std::cout << "is_const:" << std::endl;
    std::cout << "int: " << std::is_const<int>::value << std::endl;
    std::cout << "const int: " << std::is_const<const int>::value << std::endl;
    std::cout << "const int&: " << std::is_const<const int&>::value << std::endl;
    std::cout << "const int*: " << std::is_const<const int*>::value << std::endl;
    std::cout << "int* const: " << std::is_const<int* const>::value << std::endl;

    using DoublePointer = double*;
    std::cout << std::endl << "is_pointer:" << std::endl;
    std::cout << "int: " << std::is_pointer<int>::value << std::endl;
    std::cout << "int*: " << std::is_pointer<int*>::value << std::endl;
    std::cout << "double*: " << std::is_pointer<DoublePointer>::value << std::endl;

    std::cout << std::endl << "is_same:" << std::endl;
    std::cout << "<int, int>: " << std::is_same<int, int>::value << std::endl;
    std::cout << "<int, const int>: " << std::is_same<int, const int>::value << std::endl;
    std::cout << "<int*, int*>: " << std::is_same<int*, int*>::value << std::endl;
    std::cout << "<double*, double*>: " << std::is_same<DoublePointer, DoublePointer>::value << std::endl;

    std::cout << std::endl << "is_base_of:" << std::endl;
    std::cout << "<A, B>: " << std::is_base_of<A, B>::value << std::endl;
    std::cout << "<B, C>: " << std::is_base_of<B, C>::value << std::endl;
    std::cout << "<A, C>: " << std::is_base_of<A, C>::value << std::endl;
    std::cout << "<B, A>: " << std::is_base_of<B, A>::value << std::endl;
    std::cout << "<C, B>: " << std::is_base_of<C, B>::value << std::endl;
    std::cout << "<C, A>: " << std::is_base_of<C, A>::value << std::endl;
    std::cout << "<A, D>: " << std::is_base_of<A, D>::value << std::endl;
    std::cout << "<B, D>: " << std::is_base_of<B, D>::value << std::endl;
    std::cout << "<C, D>: " << std::is_base_of<C, D>::value << std::endl;

    std::cout << std::endl << "is_base_of:" << std::endl;
    std::cout << "<A*, B*>: " << std::is_convertible<A*, B*>::value << std::endl;
    std::cout << "<B*, C*>: " << std::is_convertible<B*, C*>::value << std::endl;
    std::cout << "<A*, C*>: " << std::is_convertible<A*, C*>::value << std::endl;
    std::cout << "<B*, A*>: " << std::is_convertible<B*, A*>::value << std::endl;
    std::cout << "<C*, B*>: " << std::is_convertible<C*, B*>::value << std::endl;
    std::cout << "<C*, A*>: " << std::is_convertible<C*, A*>::value << std::endl;

    return 0;
}

