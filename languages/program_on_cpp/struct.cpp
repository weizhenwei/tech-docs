#include <stdio.h>
#include <iostream>

using namespace std;

struct A {
    A() { printf("constructor of A\n"); aa = 0;}
    A(int aa) { printf("constructor of A\n"); this->aa = aa;}
    ~A() { printf("destructor of A\n"); }

    int aa;
};

struct B {
    char t:4;
    char k:4;
    unsigned short i:8;
    unsigned long m;   // sizeof(long) = 8 on x86_64, align 8 bytes, so sizeof(struct B) = 16;
};

int main() {
    // A aaa;
    char a[] = "hello world";
    char *p = a;
    cout<< sizeof(a) << endl; // 12 字节
    cout<< sizeof(p) << endl; // 4 字节 on i386, 8字节 on x86_64;

    cout<< sizeof(struct B) << endl;  // 16字节，对齐long类型;

    return 0;
}

