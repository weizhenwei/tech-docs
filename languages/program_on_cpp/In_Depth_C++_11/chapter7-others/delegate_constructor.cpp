#include <iostream>

class class_c {
public:
    int max;
    int min;
    int middle;

    class_c(int my_max) {
        std::cout << "constructor with 1 parameter" << std::endl;
        max = my_max;
        min = 0;
        middle = (max + min) / 2;
    }

    class_c (int my_max, int my_min) : class_c(my_max) {
        std::cout << "constructor with 2 parameters" << std::endl;
        min = my_min;
        middle = (max + min) / 2;
    }

    class_c (int my_max, int my_min, int my_middle) : class_c(my_max, my_min) {
        std::cout << "constructor with 3 parameters" << std::endl;
        middle = my_middle;
    }
};

int main(void) {
    class_c c1{3, 2, 1};

    return 0;
}

