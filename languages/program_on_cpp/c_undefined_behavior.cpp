#include <stdio.h>

int main() {
    int i = 0;
    int a[3] = {10, 20, 30};

    int r =  a[i++] + 2 * a[i++] + 3 * a[i++];
    printf("r = %d, i = %d\n", r, i);

    return 0;
}

