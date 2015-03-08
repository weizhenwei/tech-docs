#include <stdio.h>

void fun() {
    unsigned int a = 2013;
    int b = -2;
    int c = 0;

    while (a + b > 0) {
        a = a + b;
        c++;
    }
    
    printf("%d", c);
}

int main() {
    int *a = new int[5];
    a[0] = 1;
    a[5] = 1;

    delete []a;

    int b = 0;
    b = 3.3234343 +  2.9343423;
    printf("b = %d\n", b);

    // fun();
    unsigned char c1 = 100;
    char c2 = -101;
    printf("c1 + c2 = %d\n", c1 + c2);
    printf("c1 + c2 = %u\n", c1 + c2);
    c1 += c2;
    printf("c1 = %d\n", c1);
    printf("c1 = %u\n", c1);

    return 0;
}


