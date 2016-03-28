#include <iostream>
#include <set>

int main(void) {
    std::set<int> ss = {1, 2, 3, 4};

    for (auto& val : ss) {
        std::cout << val << std::endl;
    }

    return 0;
}


