#include <stdio.h>

void Foo(int x = 0, int y = 0) {
    printf("x = %d, y = %d\n", x, y);
}

#if 0
// ambigous function definition because of default parameters;
void Foo(int x) {
    printf("x = %d\n", x);
}
#endif

void Bar(int x = 0, int y = 0);
// void Bar(int x = 0, int y = 0) {
void Bar(int x, int y) {
    printf("x = %d, y = %d\n", x, y);
}

int main() {
    Foo();
    Foo(1);
    Foo(1, 2);

    Bar();
    Bar(1);
    Bar(1, 2);

    return 0;
}

