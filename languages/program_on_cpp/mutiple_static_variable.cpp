#include <stdio.h>
#include <stdlib.h>


/*
 * author: Eric.Wei <weizhenwei1988@gmail.com>
 * date:   2014.07.26
 *
 * description: how static local variable stored in executable file?
 *              why they can be named same?
 */
int test1()
{
    static int a = 0;

    a += 2;

    return a;
}

int test2()
{
    static int a = 0;

    a += 4;

    return a;
}

int main(int argc, char *argv[])
{
    int i = 0;
    int a1 = 0;
    int a2 = 0;
    for (i = 0; i < 10; i++) {
        a1 = test1();
        a2 = test2();

        printf("a1 = %d, a2 = %d\n", a1, a2);
    }

    return 0;
}

