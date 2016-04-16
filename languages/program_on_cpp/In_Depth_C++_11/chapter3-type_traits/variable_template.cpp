#include <iostream>

void print() {
    std::cout << "print empty" << std::endl;
}

template <typename T, typename... Args>
void print(T head, Args... args) {
    std::cout << "print parameter: " << head << std::endl;
    print(args...);
}

int main(void) {
    print(1, 2, 3, 4);
    print(1, 2, 3, 4, 5);

    return 0;
}

