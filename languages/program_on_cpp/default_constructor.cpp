#include <stdio.h>

class A {
    A(int a) : m_i(a) {}

    int m_i;
};

class B : public A {
    B(int b) : m_j(b) {}

    int m_j;
};

int main() {
    B bb[3];

    return 0;
}

