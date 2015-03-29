#include <stdio.h>
#include <stdint.h>

#define MAX 255

int main() {
    unsigned char a[MAX], i;
    // unsigned char range: 0 ~ 255
    // when i reach 255, then i++, i = 0;
    // then this is an infinite loop;
    // of course, a[255] = 255 is the fucking access violation;
    for (i = 0; i <=MAX; i++) {
        printf("i = %d\n", i);
        a[i] = i;
    }

    return 0;
}

