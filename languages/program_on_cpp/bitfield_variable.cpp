#include <stdio.h>
#include <stdlib.h>

typedef struct bitvariable {
    unsigned int base_ : 16;
    unsigned int disp_ : 15;
    bool isDouble_ : 1;
} BitVariable;

int main(int argc, char *argv[])
{
    BitVariable bv;
    int size = sizeof(bv);
    bv.base_ = (1 << 16) - 1;
    bv.disp_ = (1 << 15) - 1;
    bv.isDouble_ = true;

    fprintf(stdout, "bv size:%d\n", size);
    fprintf(stdout, "bv base:%d\n", bv.base_);
    fprintf(stdout, "bv disp:%d\n", bv.disp_);

    return 0;
}

