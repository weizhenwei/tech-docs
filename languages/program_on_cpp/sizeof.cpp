#include <stdio.h>
static int getsize(int data[]) {
    // data becomes a ordinary pointer!
    return sizeof(data);
}

struct ship {
    int year_built;
    char canons;
    int master_height;
};

static void testship() {
    struct ship my_ship;
    printf("aligned of my_ship = %d\n", __alignof__(my_ship));
    printf("aligned my_ship.canons = %d\n", __alignof__(my_ship.canons));
}

static void test_sizof_array() {
    int data1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1);
    int *data2 = data1;
    int size2 = sizeof(data2);
    int size3 = getsize(data1);

    printf("%d %d %d\n", size1, size2, size3);
}

static void test_pointer_add() {
    unsigned char *p1;
    unsigned long *p2;
    p1 = (unsigned char *)0x801000;
    p2 = (unsigned long *)0x810000;
    // at x86_64 platform, sizeof(long) = 8;

    printf("p1(char*) = %p, p1(char*) + 5 = %p\n", p1, p1 + 5);
    printf("p2(long*) = %p, p2(long*) + 5 = %p\n", p2, p2 + 5);
}


int main() {
    testship();
    test_sizof_array();
    test_pointer_add();

    return 0;
}

