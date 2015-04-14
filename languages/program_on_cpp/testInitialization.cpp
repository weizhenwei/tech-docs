#include <stdio.h>

class A {
private:
    int n1;
    int n2;
public:
    A() : n2(0), n1(n2+2) {}

    void print() {
        printf("n1 = %d, n2 = %d\n", n1, n2);
    }

};

class B {
public:
    B(int i) : m_i(i) {
        printf("explicit B constructor invoked!\n");
    }

    B() {
        B(0);  // construct a temp object and then destruct it!
        printf("default B constructor invoked!\n");
        // after this, m_i is still an random value!
    }

    ~B() {
        printf("constructor B invoked!\n");
    }

    void print() {
        printf("m_i = %d\n", m_i);
    }

private:
    B(const B&);  // no copy constructor;
    int m_i;
};

static void testA() {
    printf("at beginning of main testA\n");
    A a;
    a.print();
}

static void testB() {
    printf("at beginning of main testB\n");
    B b;
    b.print();

    // no copy constructor definition in class B.
    // B bb(b);
    // bb.print();
}


int main() {
    printf("at beginning of main function\n");
    // testA();
    testB();

    return 0;
}


