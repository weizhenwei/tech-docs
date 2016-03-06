/*
 * learn c++11 tuple usage;
 * weizhenwei
 */

#include <stdio.h>
#include <tuple>

int main(int argc, char *argv[]) {
    std::tuple<int, std::string, float> t1(10, "Test", 3.14);

    int x = 0;
    std::string s1 = "";
    float f = 0.0f;

    std::tie(x, s1, f) = t1;
    // printf("t1 = %d, %s, %f\n", t1.get<0>(), t1.get<1>().c_str(), t1.get<2>());
    printf("t1 = (%d, %s, %f)\n", x, s1.c_str(), f);

    return 0;
}

