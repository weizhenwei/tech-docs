/*
 * Test C++ 11 lambda
 *
 * Author: weizhenwei
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    auto addOne = [] (int a) -> int { return a + 1; };
    int a = 1;
    a = addOne(a);
    printf("a = %d\n", a);

    int b = 0;
    auto f = [=] { return b; };  // by value;
    b += 1;
    printf("b = %d\n", b);
    printf("b = %d\n", f());

    int bb = 0;
    auto ff = [=] () mutable { return ++bb; };  // by mutable value;
    bb += 1;
    printf("bb = %d\n", bb);
    printf("bb = %d\n", ff());
    printf("bb = %d\n", bb);

    int c = 0;
    auto g = [&] { return c; };  // by reference;
    c += 1;
    printf("c = %d\n", c);
    printf("c = %d\n", g());

    return 0;
}

