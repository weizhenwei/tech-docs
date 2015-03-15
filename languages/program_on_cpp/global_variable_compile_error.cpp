#include <stdio.h>

extern int i;

int i = 10;

i = 25;  // compile error here!

int main(int argc, char *argv[]) {
    printf("i = %d\n", i);

    return 0;
}


