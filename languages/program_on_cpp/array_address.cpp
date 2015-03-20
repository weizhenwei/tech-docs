#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int *)(&a + 1);

    printf("%p, %p\n", a, ptr);
    printf("%d, %d\n", *(a + 1), *(ptr - 1));

    int *ptr2 = (int *)(a + 1);
    printf("%p, %p\n", a, ptr2);
    printf("%d, %d\n", *(a + 1), *(ptr2 - 1));

    return 0;
}


