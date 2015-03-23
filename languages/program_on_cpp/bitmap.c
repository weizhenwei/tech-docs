#include <stdio.h>

int main(int argc, char *argv[]) {
    int a = 2;
    int b = a & 0x1;
    int c = a & 0x01;

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    if (b == c) {
        printf("b == c\n");
    } else {
        printf("b != c\n");
    }

    int x = 2, y = 1, z = 0;
    z += -x++ + ++y;
    printf("z = %d\n", z);

    return 0;
}

