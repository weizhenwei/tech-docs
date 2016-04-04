#include <iostream>
#include <type_traits>

struct A {};
struct B : A {};
struct C : B {};
struct D {};

int main(void) {
    // basic trait judgement;
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

    // is_same trait;
    std::cout << std::endl << "is_same:" << std::endl;
    std::cout << "<int, int>: " << std::is_same<int, int>::value << std::endl;
    std::cout << "<int, const int>: " << std::is_same<int, const int>::value << std::endl;
    std::cout << "<int*, int*>: " << std::is_same<int*, int*>::value << std::endl;
    std::cout << "<double*, double*>: " << std::is_same<DoublePointer, DoublePointer>::value << std::endl;

    // is_base_of trait;
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

    // is_convertible trait;
    std::cout << std::endl << "is_convertible:" << std::endl;
    std::cout << "<A*, B*>: " << std::is_convertible<A*, B*>::value << std::endl;
    std::cout << "<B*, C*>: " << std::is_convertible<B*, C*>::value << std::endl;
    std::cout << "<A*, C*>: " << std::is_convertible<A*, C*>::value << std::endl;
    std::cout << "<B*, A*>: " << std::is_convertible<B*, A*>::value << std::endl;
    std::cout << "<C*, B*>: " << std::is_convertible<C*, B*>::value << std::endl;
    std::cout << "<C*, A*>: " << std::is_convertible<C*, A*>::value << std::endl;

    // convert traits;
    std::cout << std::endl << "trait convert:" << std::endl;
    std::cout << "<const int, add const to int>: "
        << std::is_same<const int, std::add_const<int>::type>::value << std::endl;
    std::cout << "<int, remove const from const int>: "
        << std::is_same<int, std::remove_const<const int>::type>::value << std::endl;
    std::cout << "<int*, add pointer to int>: "
        << std::is_same<int*, std::add_pointer<int>::type>::value << std::endl;
    std::cout << "<int, remove pointer from int*>: "
        << std::is_same<int, std::remove_pointer<int*>::type>::value << std::endl;
    std::cout << "<int&, add lvalue from int>: "
        << std::is_same<int&, std::add_lvalue_reference<int>::type>::value << std::endl;
    std::cout << "<int&&, add rvalue from int>: "
        << std::is_same<int&&, std::add_rvalue_reference<int>::type>::value << std::endl;
    std::cout << "<int, remove reference from int&>: "
        << std::is_same<int, std::remove_reference<int&>::type>::value << std::endl;
    std::cout << "<int, remove reference from int&&>: "
        << std::is_same<int, std::remove_reference<int&&>::type>::value << std::endl;
    std::cout << "<int, remove extent from int[]>: "
        << std::is_same<int, std::remove_extent<int[]>::type>::value << std::endl;
    std::cout << "<int[2], remove extent from int[][2]>: "
        << std::is_same<int[2], std::remove_extent<int[][2]>::type>::value << std::endl;
    std::cout << "<int[2][3], remove extent from int[][2][3]>: "
        << std::is_same<int[2][3], std::remove_extent<int[][2][3]>::type>::value << std::endl;
    std::cout << "<int, remove all extent from int[][2]>: "
        << std::is_same<int, std::remove_all_extents<int[][2]>::type>::value << std::endl;
    
    return 0;
}

