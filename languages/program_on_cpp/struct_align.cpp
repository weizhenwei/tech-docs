#include <stdio.h>

struct BBB {
    long num;    // 8 bytes at x86_64 platform;
    char *name;  // 8 bytes at x86_64 platform;
    short data;  // 2 bytes at x86_64 platform;
    char ha;     // 1 byte
    short ba[5]; // 10 bytes at x86_64 platform; 
} *p;

int main() {
    long int size = sizeof(struct BBB);
    // printf("sizeof(short) = %ld\n", sizeof(short));
    printf("sizeof(struct BBB) = %ld\n", size);

    p = (struct BBB *)0x1000000;
    printf("p = %p, p + 0x200 = %p\n", p, p + 0x200);
    printf("p = %p, (unsigned long)p + 0x200 = %p\n",
            p, (void *)((unsigned long)p + 0x200));

    return 0;
}

