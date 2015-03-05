#include <stdio.h>
#include <stdlib.h>

__attribute__((constructor)) void before();
__attribute__((destructor)) void after();

void before() {
    printf("%s: before main execution\n", __func__);
}

void after() {
    printf("%s: after main execution\n", __func__);
}

int main(int argc, char *argv[])
{
    printf("%s: in main execution\n", __func__);

    return 0;
}

