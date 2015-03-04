#include <stdio.h>
#include <stdlib.h>

union test {
    short integer;
    char chars[sizeof(short)]; // sizeof(short) == 2;
};

int main(int argc, char *argv[]) {
    union test testcase;
    testcase.integer = 0x0102;

    if ((testcase.chars[0] == 0x01) && (testcase.chars[1] == 0x02)) {
        printf("Big End!\n");
    } else if ((testcase.chars[0] ==  0x02) && (testcase.chars[1] == 0x01)) {
        printf("Little End!\n");
    } else {
        printf("Unknown End!\n");
    }

    return 0;
}

