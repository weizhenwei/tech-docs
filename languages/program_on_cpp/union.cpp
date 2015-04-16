#include <stdio.h>

union uu{
    int i;
    char x[2];
} a;

union uuu{
    int i;
    struct {
        int a : 16;
        int b : 15;
        bool c : 1;
    } j;
} b;

void little_endian() {
    a.x[0] =10;  // 0x0A;
    a.x[1] =1;   // 0x01;
    printf("0X%x\n", a.i);
}

void little_endian_inside_byte() {
    b.j.a = 0x12;
    b.j.b = 0x34;
    b.j.c = 0x01;
    printf("0X%x\n", b.i);

    b.j.c = 0x00;
    printf("0X%x\n", b.i);
}

int main() {
    little_endian();
    little_endian_inside_byte();

    return 0;
}

