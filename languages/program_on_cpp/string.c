#include <stdio.h>

int main() {
    char str1[] = "hello, world";
    char str2[] = "hello, world";
    const char *str3 = "hello, world";
    const char *str4 = "hello, world";
    char *str5 = "hello, world";


    if (str1 == str2) {
        printf("str1 and str2 are same.\n");
    } else {
        printf("str1 and str2 are not same.\n");
    }

    if (str3 == str4) {
        printf("str3 and str4 are same.\n");
    } else {
        printf("str3 and str4 are not same.\n");
    }

    // compile error!
    // str3[0] = "H";

    // compile warning and running segfault;
    str5[0] = 'H';

    return 0;
}

